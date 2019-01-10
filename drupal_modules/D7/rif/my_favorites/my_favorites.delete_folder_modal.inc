<?php

	function my_favorites_delete_folder_callback($js = NULL, $nid = NULL)
	{
		if ($nid == NULL) {
			return 'NO node id was sent. Error';
		}

		//Allow the argument to be the $nid or the full node object
		if (is_numeric($nid)) {
			$folder_node_to_delete = node_load($nid);
		} else {
			$folder_node_to_delete = $nid;
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
		$form_state['build_info']['args'] = array($folder_node_to_delete);
		$output = ctools_modal_form_wrapper('my_favorites_delete_folder_form', $form_state);

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
	 * 			Delete Folder Form
	 * **************************************** */
	function my_favorites_delete_folder_form($form, $form_state, $folder_node_to_delete) {

		$form = array();

		$form['folder_nid'] = array('#type' => 'hidden', '#value' => $folder_node_to_delete->nid);

		$form['info_text'] = array(
			"#markup" => "Are you sure you want to delete the ".$folder_node_to_delete->title." folder? This action cannot be undone.",
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
			'#value' => t('No, keep this folder'),
			'#attributes' => array('class' => array('btn btn-red')),
			'#submit' => array('my_favorites_delete_folder_cancel'),
		);

		$form['actions']['submit'] = array(
			'#type' => 'submit',
			'#attributes' => array('class' => array('btn btn-blue')),
			'#value' => t('Yes, remove this folder'),
			'#submit' => array('my_favorites_delete_folder_submit'),
		);

		return $form;
	}

	function my_favorites_delete_folder_cancel(&$form, &$form_state) {
		$form_state['ajax_commands'][] = ctools_modal_command_dismiss();
	}

	function my_favorites_delete_folder_submit(&$form, &$form_state)
	{
		$folder_nid = $form_state['values']['folder_nid'];
		$folder_node = node_load($folder_nid);
		// Check if a given user can delete an entity.
		//	if ($folder_entity->access('delete')) {
		node_delete($folder_nid);
		//}

		// Tell the browser to close the modal.
		$form_state['ajax_commands'][] = ctools_modal_command_dismiss();
		$form_state['ajax_commands'][] = ajax_command_replace('#node-'.$folder_nid.'.node-favoritesfolder.node-teaser', '
			<div class="panel panel-favorites-folder-teasers">
				<div class="panel-body">The Favorite Folder <strong>'.$folder_node->title.'</strong> has been deleted</div>
			</div>
		');
		$form_state['ajax_commands'][] = ajax_command_replace('#node-'.$folder_nid.' .panel-favorites-list', '');
	}