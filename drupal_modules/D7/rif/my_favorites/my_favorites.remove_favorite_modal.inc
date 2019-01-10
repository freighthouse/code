<?php

	function my_favorites_remove_callback($js = NULL, $folder_node = NULL, $node_to_remove = NULL)
	{
		if ($node_to_remove == NULL) {
			return 'NO node id was sent. Error';
		}

		// Checking JavaScript is enabled.
		if (!$js) {
			// If JavaScript is disabled — outputting content without the popup.
			return drupal_get_form('my_favorites_remove_favorite', $folder_node, $node_to_remove);
		}

		ctools_include('ajax');
		ctools_include('modal');

		$form_state = array(
			'ajax' => TRUE,
			'title' => t($node_to_remove->title),
		);

		// Use ctools to generate ajax instructions for the browser to create
		// a form in a modal popup.
		// Use [ctools_modal_command_display(t('My first popup'), $popup_content);] If it is just content with no form
		$form_state['build_info']['args'] = array($folder_node, $node_to_remove);
		$output = ctools_modal_form_wrapper('my_favorites_remove_favorite', $form_state);

		// If the form has been submitted, there may be additional instructions
		// such as dismissing the modal popup.
		if (!empty($form_state['ajax_commands'])) {
			$output = $form_state['ajax_commands'];
		}

		// Return the ajax instructions to the browser via ajax_render().
		print ajax_render($output);
		drupal_exit();
	}


	/* ****************************************
	 * 			Remove Favorite Form
	 * **************************************** */
	function my_favorites_remove_favorite($form, &$form_state, $folder_node, $node)
	{
		$form = [];

		$form['parent_nid'] = array('#type' => 'hidden', '#value' => $folder_node->nid);
		$form['this_nid'] = array('#type' => 'hidden', '#value' => $node->nid);

		$form['info_text'] = array(
			"#markup" => "Are you sure you want to remove this item from your ".$folder_node->title." folder?",
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
			'#value' => t('No, keep this item'),
			'#attributes' => array('class' => array('btn btn-red')),
			'#submit' => array('my_favorites_remove_favorite_cancel'),
		);

		$form['actions']['submit'] = array(
			'#type' => 'submit',
			'#attributes' => array('class' => array('btn btn-blue')),
			'#value' => t('Yes, remove this item'),
		);

		return $form;
	}

	function my_favorites_remove_favorite_cancel(&$form, &$form_state) {
		$form_state['ajax_commands'][] = ctools_modal_command_dismiss();
	}

	function my_favorites_remove_favorite_submit(&$form, &$form_state)
	{
		$parent_nid = $form_state['values']['parent_nid'];
		$to_remove_nid = $form_state['values']['this_nid'];

		$parent_node = node_load($parent_nid);
		$favorites_to_search = $parent_node->field_favorite_resources['und'];

		foreach ($favorites_to_search as $index => $favorite) {
			if ($favorite['target_id'] == $to_remove_nid) {
				unset($parent_node->field_favorite_resources['und'][$index]);
				break;
			}
		}
		node_save($parent_node);
		// Tell the browser to close the modal.
		$form_state['ajax_commands'][] = ctools_modal_command_dismiss();
		$form_state['ajax_commands'][] = ajax_command_replace('#node-'.$to_remove_nid, '');
	}