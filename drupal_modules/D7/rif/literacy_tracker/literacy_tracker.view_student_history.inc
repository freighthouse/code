<?php
	function literacy_tracker_view_student_history($js = NULL, $account = NULL) {
		$debug_var = false;
		if($account == NULL) {
			global $user;
			$account = $user;
		}
		if (!$js) {
			drupal_goto("literacy-tracker/main");
		}

		ctools_include('ajax');
		ctools_include('modal');

		$form_state = array(
			'ajax' => TRUE,
			'title' => t("View History for {$account->name}"),
		);
		$form_state['build_info']['args'] = array($account);

		$output = ctools_modal_form_wrapper('literacy_tracker_view_student_history_form', $form_state, $account);
		if (!empty($form_state['ajax_commands'])) {
			$output = $form_state['ajax_commands'];
		}
		if (!empty($form_state['executed'])) {
			$output[] = ctools_modal_command_dismiss();
		}

		print ajax_render($output);
		drupal_exit();
	}

	function literacy_tracker_view_student_history_form($form, $form_state, $account = NULL) {
		if($account == NULL) {
			global $user;
			$account = $user;
		}

		$user_query = new EntityFieldQuery();
		$user_query->entityCondition('entity_type', 'reading_challenge')
			->propertyCondition('student_id', $account->uid, '=');
		$results = $user_query->execute();

		if(isset($results['reading_challenge'])) {
			$reading_challenges = entity_load('reading_challenge', array_keys($results['reading_challenge']));
		}
		$labels = array();
		$data = array();
		$backgroundColor = array();
		$borderColor = array();
		$counter = 1;
		$colors = array(
			[255,99,132],
			[54,162,235],
			[255,206,86],
			[75,192,192],
			[153,102,255],
			[255,159,64]
		);
		$background_alpha = 0.2;
		$border_alpha = 1;
		foreach($reading_challenges as $index => $reading_challenge) {
			$color_string = "rgba({$colors[$counter%6][0]},{$colors[$counter%6][1]},{$colors[$counter%6][2]}";
			$backgroundColor[] = "{$color_string},{$background_alpha})";
			$borderColor[] = "{$color_string},{$border_alpha})";
			$labels[] = $counter++;
			$data[] = $reading_challenge->weighted_score;
		}

		$modal_body = theme('literacy_tracker__view_student_history', array(
			'test_var' => 3,
			'data' => $data,
			'labels' => $labels,
			'background_colors' => $backgroundColor,
			'border_colors' => $borderColor,
		));

		$form = array();
		$form['modal-body'] = array(
			'#markup' => $modal_body,
		);

		$form['actions'] = array(
			'#type' => 'fieldset',
			'#attributes' => array('class' => array('modal-actions')),
		);

		$form['actions']['submit'] = array(
			'#type' => 'submit',
			'#value' => t('Back to Group'),
			'#attributes' => array(
				'class' => array('btn btn-blue'),
			),
		);
		return $form;
	}