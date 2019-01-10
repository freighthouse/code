<?php

	function literacy_tracker_edit_callback($js = NULL, $node_to_edit = NULL) {
		if ($node_to_edit == NULL) {
			return 'NO node id was sent. Error';
		}
		// Code derived from: https://gist.github.com/mrconnerton/1979037
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

		$form_state = array(
			'ajax' => TRUE,
			'title' => t("Edit Literacy Tracker Group"),
		);

		// Use ctools to generate ajax instructions for the browser to create
		// a form in a modal popup.
		// Use [ctools_modal_command_display(t('My first popup'), $popup_content);] If it is just content with no form
		$form_state['build_info']['args'] = array($node_to_edit);
		$output = ctools_modal_form_wrapper('lt_reading_groups_node_form', $form_state);
		//$output = ctools_modal_form_wrapper('literacy_tracker_add_reading_group', $form_state);
		//$output = ctools_modal_form_wrapper('literacy_tracker_add_lt_reading_groups_form', $form_state);

		// If the form has been submitted, there may be additional instructions
		// such as dismissing the modal popup.
		if (!empty($form_state['ajax_commands'])) {
			$output = $form_state['ajax_commands'];
		}

		// This means the form has been exectued
		if (!empty($form_state['executed'])) {
			$output = array();
			// Close the modal
			drupal_get_messages();
			$output[] = ctools_modal_command_dismiss();
			//$output[] = ctools_ajax_command_reload();

			$block = module_invoke('literacy_tracker', 'block_view', 'lt_reading_groups');
			$html = render($block['content']);
			$output[] = ajax_command_html('.pane-literacy-tracker-lt-reading-groups .pane-content', $html);

		}

		// Return the ajax instructions to the browser via ajax_render().
		print ajax_render($output);
		drupal_exit();
	}
