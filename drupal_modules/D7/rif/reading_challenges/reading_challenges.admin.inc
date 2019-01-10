<?php
	function reading_challenge_form($form, &$form_state, $reading_challenge = NULL) {
		$form['name'] = array(
			'#title' => t('Name'),
			'#type' => 'textfield',
			'#default_value' => isset($reading_challenge->name) ? $reading_challenge->name : '',
			'#description' => t('Reaching Challenge Name.'),
			'#required' => TRUE,
			'#weight' => -50,
		);

		$form['student_id'] = array(
			'#title' => t('Student ID'),
			'#type' => 'textfield',
			'#description' => t('Student ID who took this reading challenge.'),
			'#default_value' => isset($reading_challenge->student_id) ? $reading_challenge->student_id : '',
			'#weight' => -40,
		);
		$form['percentile'] = array(
			'#title' => t('Percentile'),
			'#type' => 'textfield',
			'#description' => t('Percentile Score of this reading challenge.'),
			'#default_value' => isset($reading_challenge->percentile) ? $reading_challenge->percentile : '',
			'#weight' => -30,
		);

		$form['actions'] = array(
			'#type' => 'actions',
			'submit' => array(
				'#type' => 'submit',
				'#value' => isset($reading_challenge->id) ? t('Update Reading Challenge') : t('Save Reading Challenge'),
			),
		);
		return $form;
	}

	function reading_challenge_form_submit($form, &$form_state) {
		$reading_challenge = entity_ui_form_submit_build_entity($form, $form_state);
		$reading_challenge->save();
		drupal_set_message(t('@name reading challenge has been saved.', array('@name' => $reading_challenge->name)));
		$form_state['redirect'] = 'admin/content/reading-challenge';
	}