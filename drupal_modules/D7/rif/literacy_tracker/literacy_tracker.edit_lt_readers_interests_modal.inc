<?php

	function literacy_tracker_edit_lt_readers_interests_callback($js = NULL, $user_to_edit = NULL) {
		global $user;
		$user_to_edit = user_load($user->uid);

		// Code derived from: https://gist.github.com/mrconnerton/1979037
		if ($user_to_edit == NULL) {
			return 'NO node id was sent. Error';
		}
		// Checking JavaScript is enabled.
		if (!$js) {
			//drupal_exit();
			//return;
			// If JavaScript is disabled — outputting content without the popup.
			drupal_goto("literacy-tracker/main");
			//return drupal_get_form('literacy_tracker_add_favorite_form', $node_to_add);
		}

        //module_load_include('inc', 'user', 'user.pages');
        
		ctools_include('ajax');
		ctools_include('modal');

		$form_state = array(
			'ajax' => TRUE,
			'title' => t("Add Interests for {$user_to_edit->name}"),
		);

		// Use ctools to generate ajax instructions for the browser to create a form in a modal popup.
		$output = ctools_modal_form_wrapper('literacy_tracker_lt_readers_interests_form', $form_state);


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
			//One way to do this is with a form reload but it isn't always the most elegant.
			$output[] = ctools_ajax_command_reload();
			/*
			$html = views_embed_view('my_view', 'my_display');
			$output[] = ajax_command_html('.view-display-id-my_display', $html);
			*/
			$block = module_invoke('literacy_tracker', 'block_view', 'lt_reading_groups');
			$html = render($block['content']);
			$output[] = ajax_command_html('.pane-literacy-tracker-lt-reading-groups .pane-content', $html);
		}

		// Return the ajax instructions to the browser via ajax_render().
		print ajax_render($output);
		drupal_exit();
	}

	function literacy_tracker_lt_readers_interests_form($form, $form_state)
	{
		global $user;
		$reader_profile = profile2_load_by_user($user);
		if (empty($reader_profile)) {
			$reader_profile = profile2_create(array(
				'type' => 'literacy_tracker_reader',
				'uid' => $user->uid,
			));
		}
		$profile_emw = $reader_profile['literacy_tracker_reader']->wrapper();

		// ************************************************
		// 		We're ready so lets build the form
		// ************************************************
		
		$form = array();
		$form['#attributes'] = array('class' => 'lt-add-readers-interests-form');
		$form['#attached']['css'][] = drupal_get_path('module', 'literacy_tracker') .  '/css/interests-modal.css';

		$form['header'] = array(
			'#markup' => '<p class="text-center"><strong>Choose your interests below. Be sure to select all that apply.</strong></p>',
		);

		$options = _vocab_name_to_options_array('student_interests');
//		$form['student_interests'] = array(
//			'#prefix' => '<div id="student-interests">',
//			'#suffix' => '</div>',
//			'#type' => 'select',
//			'#multiple' => true,
//			'#title' => '',
//			'#options' => $options,
//		);

		$form['interests'] = array(
			'#type' => 'fieldset',
			'#attributes' => array('class' => array('modal-interests row')),
			'#tree' => true,
		);

		foreach($options as $tid => $t_name) {
			$taxonomy_entity = taxonomy_term_load($tid);
			$interest_emw = entity_metadata_wrapper('taxonomy_term', $tid);
			$icon_url = file_create_url($interest_emw->field_icon->value()['uri']);
			$icon_highlighted_url = file_create_url($interest_emw->field_icon_highlighted->value()['uri']);
			$form['interests'][$tid] = array(
				'#type' => 'checkbox',
				'#title' => $t_name,
				'#default_value' => FALSE,
				'#attributes' => array('class' => array('col-md-3')),
				'#wrapped_label' => TRUE,
				'#input_suffix' => "
					<img class='icon icon-normal img-responsive' src='{$icon_url}'>
					<img class='icon icon-highlighted img-responsive' src='{$icon_highlighted_url}'>
				",
				'#prefix' => "
					<div class='col-md-3 interests-checkbox'>",
				'#suffix' => "
					</div>",
			);
			//<div class='icon icon-highlighted' style='background-image: url({$icon_highlighted_url});'>
			//<div class='icon' style='background-image: url({$icon_url});'>
		}

		foreach($profile_emw->field_reader_interests->value() as $index => $interest){
			if(isset($form['interests'][$interest->tid])) {
				$form['interests'][$interest->tid]['#default_value'] = TRUE;
			}
		}

		$form['actions'] = array(
			'#type' => 'fieldset',
			'#attributes' => array('class' => array('modal-actions')),
		);

		$form['actions']['submit'] = array(
			'#type' => 'submit',
			'#value' => t('Submit'),
			'#attributes' => array(
				'class' => array('btn btn-blue btn-add-material-all'),
			),
		);
		return $form;
	}

	function literacy_tracker_lt_readers_interests_form_validate(&$form, &$form_state) {
		//TODO: Only if needed
	}

	function literacy_tracker_lt_readers_interests_form_submit(&$form, &$form_state)
	{
		global $user;
		//$account = user_save(null, $newUser);
		$interests_array = $form_state['values']['interests'];

		foreach($interests_array as $tid => $is_selected) {
			if($is_selected) {
				$selected_interests[] = $tid;
			}
		}

		$reader_profile = profile2_load_by_user($user);
		if (empty($reader_profile)) {
			$reader_profile = profile2_create(array(
				'type' => 'literacy_tracker_reader',
				'uid' => $user->uid,
			));
		}

		if(!isset($reader_profile['literacy_tracker_reader'])){
			 return; // Really weird error;
		}
		$profile_emw = $reader_profile['literacy_tracker_reader']->wrapper();

		//save reader interests field
		$profile_emw->field_reader_interests = $selected_interests;
		$profile_emw->save();

		drupal_set_message("You have successfully added your interests.");
	}

	function _vocab_name_to_options_array($vocabulary_name) {
		$toReturn = array();
		$terms = taxonomy_get_tree(taxonomy_vocabulary_machine_name_load($vocabulary_name)->vid);

		foreach($terms as $data) {
			$toReturn[$data->tid] = $data->name;
		}

		return $toReturn;
	}