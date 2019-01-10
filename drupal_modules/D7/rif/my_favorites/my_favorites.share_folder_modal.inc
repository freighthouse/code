<?php

	function my_favorites_share_folder_callback($js = NULL, $nid = NULL)
	{
		if ($nid == NULL) {
			return 'NO node id was sent. Error';
		}

		//Allow the argument to be the $nid or the full node object
		if (is_numeric($nid)) {
			$folder_node_to_share = node_load($nid);
		} else {
			$folder_node_to_share = $nid;
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
			'title' => t('Share Settings'),
		);

		// Use ctools to generate ajax instructions for the browser to create
		// a form in a modal popup.
		// Use [ctools_modal_command_display(t('My first popup'), $popup_content);] If it is just content with no form
		$form_state['build_info']['args'] = array($folder_node_to_share);
		$output = ctools_modal_form_wrapper('my_favorites_rename_folder_form', $form_state);

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
	function my_favorites_rename_folder_form($form, $form_state, $node_to_edit) {

		$node_to_update_wrapper = entity_metadata_wrapper('node', $node_to_edit);

		$form = array();

		// Get Node Values to display throughout the form
		$title = $node_to_update_wrapper->label();
		$current_status = $node_to_update_wrapper->field_shared->value();
		global $base_url;
		$path = $base_url;

		$form['folder_nid'] = array('#type' => 'hidden', '#value' => $node_to_edit->nid);

		$form['info_text'] = array(
			"#markup" => "Folder: ".$title,
			'#prefix' => '<p>',
			'#suffix' => '</p>',
		);

		$form['share_status'] = array(
			'#type' => 'checkbox',
			'#title' => t('Share'),
			'#default_value' => $current_status,
			'#description' => t('Should this favorites list be shared?'),
		);

		$form['shareable_link'] = array(
			'#type' => 'textfield',
			'#attributes' => array(
				'class' => array('form-control'),
			),
			'#disabled' => TRUE,
			'#title' => t('Shareable Link'),
			'#size' => 60,
			'#maxlength' => 128,
			'#default_value' => $path.'/literacy-central/shared-favorites/'.$node_to_update_wrapper->getIdentifier(),
			'#states' => array(
				// Hide the settings when the cancel notify checkbox is disabled.
				'visible' => array(
					':input[name="share_status"]' => array('checked' => TRUE),
				),
			),
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
			'#value' => t('Discard Changes'),
			'#attributes' => array('class' => array('btn btn-red')),
			'#limit_validation_errors' => array(),
			'#submit' => array('my_favorites_rename_folder_cancel'),
		);
		$form['actions']['submit'] = array(
			'#type' => 'submit',
			'#attributes' => array('class' => array('btn btn-blue')),
			'#value' => t('Apply Changes'),
			'#submit' => array('my_favorites_rename_folder_submit'),
		);

		return $form;
	}

	function my_favorites_rename_folder_cancel(&$form, &$form_state) {
		$form_state['ajax_commands'][] = ctools_modal_command_dismiss();
	}

	function my_favorites_rename_folder_submit(&$form, &$form_state)
	{
		$new_status = $form_state['values']['share_status'];
		$node_to_update = $form_state['values']['folder_nid'];
		$node_to_update_wrapper = entity_metadata_wrapper('node', $node_to_update);
		$node_to_update_wrapper->field_shared->set($new_status);
		$node_to_update_wrapper->save();

		$new_status_html = $new_status ? 'shared' : 'private';
		$form_state['ajax_commands'][] = ctools_modal_command_dismiss();
		$form_state['ajax_commands'][] = ajax_command_replace('#node-' . $node_to_update . ' .shared-status', '<span class="shared-status">'. $new_status_html . '</span>');
		/*$folder_nid = $form_state['values']['folder_nid'];
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
		$form_state['ajax_commands'][] = ajax_command_replace('#node-'.$folder_nid.' .panel-favorites-list', '');*/
	}