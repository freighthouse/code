<?php

	function literacy_tracker_delete_callback($js = NULL, $nid = NULL)
	{
		if ($nid == NULL) {
			return 'NO node id was sent. Error';
		}

		//Allow the argument to be the $nid or the full node object
		if (is_numeric($nid)) {
			$group_node_to_delete = node_load($nid);
		} else {
			$group_node_to_delete = $nid;
		}

		// Checking JavaScript is enabled.
		if (!$js) {
			//drupal_exit();
			//return;
			// If JavaScript is disabled — outputting content without the popup.
			$alias = drupal_get_path_alias($nid);
			drupal_goto("node/".$alias);
			//return drupal_get_form('my_favorites_add_favorite_form', $node_to_add);
		}
		ctools_include('ajax');
		ctools_include('modal');

		$form_state = array(
			'ajax' => TRUE,
			'title' => t('Delete'),
		);

		// Use ctools to generate ajax instructions for the browser to create
		// a form in a modal popup.
		// Use [ctools_modal_command_display(t('My first popup'), $popup_content);] If it is just content with no form
		$form_state['build_info']['args'] = array($group_node_to_delete);
		$output = ctools_modal_form_wrapper('my_favorites_delete_group_form', $form_state);

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
	 * 			Delete Reading Group Form
	 * **************************************** */
	function literacy_tracker_delete_form($form, $form_state, $group_node_to_delete) {
	
	$form = array();
	
	$form['group_nid'] = array('#type' => 'hidden', '#value' => $group_node_to_delete->nid);
	
	$form['info_text'] = array(
		"#markup" => "Are you sure you want to delete the ".$group_node_to_delete->title." group? This action cannot be undone.",
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
		'#value' => t('No, keep this group'),
		'#attributes' => array('class' => array('btn btn-red')),
		'#submit' => array('literacy_tracker_delete_group_cancel'),
	);
	
	$form['actions']['submit'] = array(
		'#type' => 'submit',
		'#attributes' => array('class' => array('btn btn-blue')),
		'#value' => t('Yes, remove this group'),
		'#submit' => array('literacy_tracker_delete_group_submit'),
	);
	
	return $form;
}
	
	function literacy_tracker_delete_cancel(&$form, &$form_state) {
		$form_state['ajax_commands'][] = ctools_modal_command_dismiss();
	}
	
	function literacy_tracker_delete_submit(&$form, &$form_state)
	{
		$group_nid = $form_state['values']['group_nid'];
		$group_node = node_load($group_nid);
		$group_nid->status = 1;
		node_save($group_nid);
		
		// Tell the browser to close the modal.
		$form_state['ajax_commands'][] = ctools_modal_command_dismiss();
		$form_state['ajax_commands'][] = ajax_command_replace('#node-'.$group_nid.'.node-favoritesgroup.node-teaser', '
			<div class="panel panel-favorites-group-teasers">
				<div class="panel-body">The Reading Group <strong>'.$group_node->title.'</strong> has been deleted</div>
			</div>
		');
		$form_state['ajax_commands'][] = ajax_command_replace('#node-'.$group_nid.' .panel-favorites-list', '');
	}