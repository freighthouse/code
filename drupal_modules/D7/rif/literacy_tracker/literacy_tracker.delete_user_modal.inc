<?php

	function literacy_tracker_delete_user_callback($js = NULL, $user= NULL) {
		$debug_val = true;
		// Code derived from: https://gist.github.com/mrconnerton/1979037
		if ($user == NULL) {
			return 'No UID was sent. Error';
		}
		// Checking JavaScript is enabled.
		if (!$js) {
			//drupal_exit();
			//return;
			// If JavaScript is disabled — outputting content without the popup.
			drupal_goto("literacy-tracker/main");
			//return drupal_get_form('literacy_tracker_add_favorite_form', $node_to_add);
		}

		module_load_include('inc', 'node', 'node.pages');

		ctools_include('ajax');
		ctools_include('modal');

		$emw_user = entity_metadata_wrapper( 'user', $user);

		$form_state = array(
			'ajax' => TRUE,
			'title' => t("Delete User {$emw_user->field_first_name->value()} {$emw_user->field_last_name->value()}"),
			'user_id' => $emw_user->uid->value(),
		);
		$form_state['build_info']['args'] = array($emw_user);

		// Use ctools to generate ajax instructions for the browser to create a form in a modal popup.
		$output = ctools_modal_form_wrapper('literacy_tracker_delete_user_form', $form_state);

		//$output = ctools_modal_form_wrapper('literacy_tracker_add_reading_group', $form_state);
		//$output = ctools_modal_form_wrapper('literacy_tracker_add_lt_reading_groups_form', $form_state);

		// If the form has been submitted, there may be additional instructions
		// such as dismissing the modal popup.
		if (!empty($form_state['ajax_commands'])) {
			$output = $form_state['ajax_commands'];
		}
		
		if (!empty($form_state['executed'])) {
			$output = array();
			// Close the modal
			drupal_get_messages();
			$output[] = ctools_modal_command_dismiss();
			//One way to do this is with a form reload but it isn't always the most elegant.
			$output[] = ctools_ajax_command_reload();
			/*
			$html = views_embed_view('my_view', 'my_display');
			$output[] = ajax_command_html('.view-display-id-my_display', $html);
			*/
//			$block = module_invoke('literacy_tracker', 'block_view', 'lt_reading_groups');
//			$html = render($block['content']);
//			$output[] = ajax_command_html('.pane-literacy-tracker-lt-reading-groups .pane-content', $html);
		}

		// Return the ajax instructions to the browser via ajax_render().
		print ajax_render($output);
		drupal_exit();
	}

	/* ****************************************
	 * 			Delete User Form
	 * **************************************** */
	
	function literacy_tracker_delete_user_form($form, $form_state, $user_to_delete) {
		
		$emw_user = entity_metadata_wrapper( 'user', $user_to_delete );
		
		$form = array();
		
		$form['user_to_delete'] = array('#type' => 'hidden', '#value' => $user_to_delete->getIdentifier());
		
		$form['info_text'] = array(
			"#markup" => "Are you sure you want to delete the user ".$emw_user->field_first_name->value()."? This action cannot be undone.",
			'#prefix' => '<p>',
			'#suffix' => '</p>',
		);
		
		$form['actions'] = array(
			'#type' => 'fieldset',
			'#attributes' => array('class' => array('modal-actions')),
			'#prefix' => '<fieldset class="modal-actions"><div class="btn-group">',
			'#suffix' => '</div></fieldset>',
			'#theme_wrappers' => array(),
		);
		
		$form['actions']['cancel'] = array(
			'#type' => 'submit',
			'#value' => t('No, keep this user'),
			'#attributes' => array('class' => array('btn btn-red pull-left')),
			'#submit' => array('literacy_tracker_delete_user_cancel'),
		);
		
		$form['actions']['submit'] = array(
			'#type' => 'submit',
			'#attributes' => array('class' => array('btn btn-blue pull-right')),
			'#value' => t('Yes, delete this user'),
			'#submit' => array('literacy_tracker_delete_user_submit'),
		);
		
		return $form;
	}
	
	function literacy_tracker_delete_user_cancel(&$form, &$form_state) {
		$form_state['ajax_commands'][] = ctools_modal_command_dismiss();
	}
	
	function literacy_tracker_delete_user_submit(&$form, &$form_state)
	{
		$user = $form_state['values']['user_to_delete'];
		user_delete($user);
		
		// Tell the browser to close the modal.
		$form_state['ajax_commands'][] = ctools_modal_command_dismiss();
		$form_state['ajax_commands'][] = ajax_command_replace('#node-'.$group_nid.'.node-favoritesgroup.node-teaser', '
			<div class="panel panel-favorites-group-teasers">
				<div class="panel-body">The user <strong>'.$user->name.'</strong> has been deleted</div>
			</div>
		');
		$form_state['ajax_commands'][] = ajax_command_replace('#node-'.$group_nid.' .panel-favorites-list', '');
	}