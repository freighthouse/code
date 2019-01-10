<?php
	function build_reading_challenge($node_to_show = NULL) {
		drupal_page_is_cacheable(FALSE);
		$variables = array();

		if($node_to_show == NULL) {
			$node_to_show = find_appropriate_reading_passage($variables);
			//drupal_goto("literacy-tracker/student/reading-challenge/{$node_to_show}");
		}

		$emw_node = entity_metadata_wrapper('node', $node_to_show);

		$body_text = $emw_node->get('body')->value()['value'];
		$body_text_stripped_tags = strip_tags($body_text);
		$body_text_replaced = str_replace(['_', '.', ';', ',', '&nbsp'], ' ', $body_text_stripped_tags);
		$body_text_whitespace_reduced = preg_replace('!\s+!', ' ', $body_text_replaced);
		$body_text_trimmed = trim($body_text_whitespace_reduced);
		$body_text_split = explode(' ', $body_text_trimmed);
		$body_text_count = count($body_text_split);

		$form = drupal_get_form('reading_challenges_complete_reading_challenge_form', $emw_node, $body_text_count);

		$output = theme('reading_challenges__reading_passage', array(
			'reading_passage_title' => $emw_node->get('field_display_title')->value(),
			'body_text' => $body_text,
			'submit_form' => $form,
		));
		return $output;
	}

	/* ****************************************
	 * 		Reading Challenge Form
	 * **************************************** */
	function reading_challenges_complete_reading_challenge_form($form, &$form_state, $reading_passage_emw, $body_text_count = 100) {

		$reading_passage_emw->get('body')->value()['value'];

		$form = array(
			'#attributes' => array(
				'class' => array('reading-challenge-form'),
			),
			'#attached' => array(
				'css' => array(
					drupal_get_path('module', 'reading_challenges') . '/css/reading_challenges.css',
				),
				'js' => array(
					drupal_get_path('module', 'reading_challenges') . '/js/reading_challenges.js',
				)
			),
		);
		$form['passage'] = array(
			'#markup' => $reading_passage_emw->get('body')->value()['value'],
			'#prefix' => "<div id='words' class='reading-passage-body'>",
			'#suffix' => "</div>",
		);

		$debug_val = 'test';
		$time_started = time();
		if (isset($form_state['input']['date_stamp_start']) && $form_state['input']['date_stamp_start']) {
			$time_started = $form_state['input']['date_stamp_start'];
		}

		$form['date_stamp_start'] = array(
			'#type' => 'hidden',
			'#value' => $time_started,
		);

		$form['word_count'] = array(
			'#type' => 'hidden',
			'#value' => $body_text_count,
		);

		$form['reading_passage_id'] = array(
			'#type' => 'hidden',
			'#value' => $reading_passage_emw->getIdentifier(),
		);

        $form['header'] = array(
          '#markup' => '<h3>Click Stop when you are done.</h3>',
          '#prefix' => '<div class="timer-header">',
          '#suffix' => '</div>'
        );

		$form['actions'] = array(
			'#type' => 'fieldset',
			'#attributes' => array('class' => array('actions navbar-fixed-bottom')),
		);

		$form['actions']['timer_display'] = array(
			'#markup' => '
				<div class="timer-container">
					<div class="timer-counter">
						<p>Time Taken: <span class="time-box"><span class="minutes">00</span>:<span class="seconds">00</span></span></p>
					</div>
				</div>
			',
		);
		$form['actions']['words_clicked'] = array(
			'#type' => 'textfield',
			'#title' => t('Words Clicked:'),
			'#required' => TRUE,
			'#default_value' => 0,
			'#size' => 3,
			'#maxlength' => 3,
		);

		$form['actions']['submit'] = array(
			'#type' => 'submit',
			'#value' => t('Stop'),
			'#attributes' => array(
				'class' => array('btn btn-yellow btn-add-material-all'),
			),
		);

		return $form;
	}

	function reading_challenges_complete_reading_challenge_form_submit($form, &$form_state) {

		global $user;

		$time_started = $form_state['values']['date_stamp_start'];
		$time_ended = time();
		$raw_time_taken = $time_ended - $time_started;
		if($raw_time_taken > 300) {
			$raw_time_taken = 300;
		}

		$passage_nid = $form_state['values']['reading_passage_id'];
		$passage_emw = entity_metadata_wrapper('node', $passage_nid);

		// Get Total Words and Words Incorrect from form
		$total_words = $form_state['values']['word_count'];
		$words_incorrect = $form_state['values']['words_clicked'];
		$words_correct = $total_words - $words_incorrect;
		$time_taken = $raw_time_taken;
		$words_correct_per_minute = $words_correct/($time_taken/60);
		$reading_passage_grade_level = $passage_emw->field_fry_reading_score->value();

		$percentile = _get_percentile_from_wcpm($words_correct_per_minute, $reading_passage_grade_level);

		$score = _get_score_from_percentile($percentile, $passage_emw->field_fry_reading_score->value());

		$entity_type = 'reading_challenge';
		$new_entity = entity_create($entity_type, array('type' => $entity_type));
		$new_entity->name = "Programmatic Entity";
		$new_entity->reading_passage_id = $form_state['values']['reading_passage_id'];
		$new_entity->reading_passage_grade_level = $reading_passage_grade_level;
		$new_entity->student_id = $user->uid;
		$new_entity->total_words = $total_words;
		$new_entity->words_incorrect = $words_incorrect;
		$new_entity->words_correct = $words_correct;
		$new_entity->duration = $time_taken;
		$new_entity->words_correct_per_minute = $words_correct_per_minute;
		$new_entity->percentile = $percentile;
		$new_entity->weighted_score = $score;


		entity_save($entity_type, $new_entity);

		// Redirect this to a completed page
		$form_state['redirect'] = 'literacy-tracker/student/completed/'.$new_entity->identifier();

//		foreach($result['reading_challenge'] as $index => $current_entity) {
//			$entity = entity_load($entity_type, array($index));
//			$entity->name = "Updated";
//			entity_save($entity_type, $entity);
//		}

//
//		$wrapper = entity_metadata_wrapper('entity', $new_entity);
//
//		$wrapper->name->set("Test Entity");
//		$wrapper->student_id->set($user->uid);
//
//		$wrapper->save();
	}

	/* ****************************************
	 * 		Reading Passage Helper Functions
	 * **************************************** */
	function _get_percentile_from_wcpm($words_correct_per_minute, $grade_level) {
		// Get actual percentile from chart.
		if($grade_level < 1) { $grade_level = 1; }
		if($grade_level > 6) { $grade_level = 6; }

		$x = $words_correct_per_minute;

		$percentile_score = 0.5;
		switch($grade_level) {
			case 1:
				//http://www.wolframalpha.com/input/?i=lograthmic+fit+%7B%7B9,10%7D,%7B16,25%7D,%7B29,50%7D,%7B59,75%7D,+%7B97,90%7D%7D
				//lograthmic fit {{9,10},{16,25},{29,50},{59,75}, {97,90}}
				if($x > 110) {$percentile_score = 100;} else
				$percentile_score = 34.704 * log(0.141266 * $x); //logarithmic fit for 1st grade percentile levels.
				break;
			case 2:
				//cubic fit {{35,10},{59,25},{84,50},{109,75}, {131,90}}
				//graph -0.0000989106 x^3 + 0.0251142 x^2 - 1.06357 x + 20.6887
				if($x > 150) {$percentile_score = 100;} else
				$percentile_score = (-0.0000989106 * pow($x, 3)) + (0.0251142*pow($x,2)) - (1.06357*$x) + 20.6887;
				break;
			case 3:
				//logarithmic fit {{62,10},{79,25},{97,50},{137,75}, {161,90}}
				if($x > 180) {$percentile_score = 100;} else
				$percentile_score = 85.0714 * log(0.0178314 * $x); //logarithmic fit for 3rd grade percentile levels.
				break;
			case 4:
				//cubic fit {{71,10},{95,25},{120,50},{143,75}, {168,90}}
				// graph -0.000121947 x^3 + 0.0437416 x^2 - 4.11837 x + 125.647
				if($x > 175) {$percentile_score = 100;} else
				$percentile_score = (-0.000121947* pow($x, 3)) + (0.0437416*pow($x,2)) - (4.11837*$x) + 125.647;
				break;
			case 5:
				//cubic fit {{84,10},{109,25},{133,50},{160,75}, {183,90}}
				//graph -0.0000955032 x^3 + 0.0383196 x^2 - 4.08314 x + 139.06
				if($x > 200) {$percentile_score = 100;} else
				$percentile_score = (-0.0000955032 * pow($x, 3)) + (0.0383196*pow($x,2)) - (4.08314*$x) + 139.06;
				break;
			case 6:
				// cubic fit {{91,10},{116,25},{145,50},{166,75}, {195,90}}
				// graph -0.000108689 x^3 + 0.0466846 x^2 - 5.62132 x + 217.211
				if($x > 200) {$percentile_score = 100;} else
				$percentile_score = (-0.000108689 * pow($x, 3)) + (0.0466846*pow($x,2)) - (5.62132*$x) + 217.211;
				break;
		}

		if($percentile_score < 0) { $percentile_score = 0; }
		if($percentile_score > 100) { $percentile_score = 100; }

		return $percentile_score;
	}

	// Assuming percentile is a value 0.1-0.9
	function _get_score_from_percentile($percentile, $grade_level) {
		$whole_percentile = $percentile/10;
		$score = ($whole_percentile - 1)/8;
		// If score is less than 5 then lets actually exasperate their lower score
		if ($score < 0.5) {
			$adjusted_score = (pow($score-1, 2)/16) - 1;
			$adjusted_score /= 5;
		} else {
			$adjusted_score = 0;
		}
		$score += $adjusted_score;

		return $score + $grade_level;
	}

	/* ****************************************
	 * 		Reading Passage Helper Functions
	 * **************************************** */
	function find_appropriate_reading_passage(&$variables, $account = NULL) {
		if($account == NULL) {
			global $user;
			$account = $user;
		}

		$emw_account = entity_metadata_wrapper('user', $account);
		$reader_profile = profile2_load_by_user($account);
		// for-prod: Remove the query check for reader users (Just delete these next few lines)
		if(isset(drupal_get_query_parameters()['reading_level']) && $set_reading_level = drupal_get_query_parameters()['reading_level']){
			return _find_reading_passage_in_range($set_reading_level, $set_reading_level);
		}
		if(isset($reader_profile['literacy_tracker_reader'])){
			$reader_wrapper = $reader_profile['literacy_tracker_reader']->wrapper();
		} else {
			// This is an admin/teacher user viewing this page...
			// Find a reading passage from any range unless a query parameter is set.
			if($set_reading_level = drupal_get_query_parameters()['reading_level']){
				return _find_reading_passage_in_range($set_reading_level, $set_reading_level);
			}
			return _find_reading_passage_in_range(0, 15);
		}

		$guestimated_reading_level = _get_guestimated_reading_grade_level();

		// only take the floor and ceil if the guestimated reading level is < x.2 && > x.8
		$grade_whole_level = floor($guestimated_reading_level);
		$grade_fraction = $guestimated_reading_level - $grade_whole_level;
		if(round($grade_fraction, 1) < 0.2){
			$min_grade = $grade_whole_level - 1;
			$max_grade = $grade_whole_level;
		} else if (round($grade_fraction, 1) > 0.8) {
			$min_grade = $grade_whole_level;
			$max_grade = $grade_whole_level + 1;
		} else {
			$min_grade = $grade_whole_level;
			$max_grade = $grade_whole_level;
		}

		// Limit the grade level to a variance of one grade level. So a user with grade level 4 will only ever be able to get reading passages within the range of 3-5
        global $user;
        $reader_profile = profile2_load_by_user($user);
        if(isset($reader_profile['literacy_tracker_reader'])) {
          $reader_profile_wrapper = $reader_profile['literacy_tracker_reader']->wrapper();

          $current_grade_level = $reader_profile_wrapper->field_grade_level->value();
          $current_grade_value = intval($current_grade_level->name);
          $min_grade = limit_value($min_grade, $current_grade_value-1, $current_grade_value+1);
          $max_grade = limit_value($max_grade, $current_grade_value-1, $current_grade_value+1);
        }

          return _find_reading_passage_in_range($min_grade, $max_grade);
	}

//	function _find_reading_passage_from_spread($score, $spread) {
//		$min_score = $score - $spread;
//		$max_score = $score + $spread;
//		return _find_reading_passage_in_range($min_score, $max_score);
//	}

	function _find_reading_passage_in_range($min, $max) {
		$possible_passages = _get_all_reading_passages_in_range($min, $max);
		$refined_passages_list = _filter_reading_passage_list($possible_passages);
		$chosen_passage = _choose_reading_passage_from_list($refined_passages_list, false);
		$emw_node = entity_metadata_wrapper('node', $chosen_passage);

		//drupal_set_message(t('Chosen Passage Grade Level: @chosen_passage', array('@chosen_passage' => $emw_node->field_fry_reading_score->value())), 'status');
		return $chosen_passage;
	}

	function _get_all_reading_passages_in_range($min, $max) {
		// Find all reading passages in the system that:
		// - field_is_reading_challenge set to TRUE
		// - has field_fry_reading_score
		// - field_fry_reading_score > $min
		// - field_fry_reading_score < $max
		$type = 'beeline_experience';

		$query = new EntityFieldQuery;
		$result = $query
			->entityCondition('entity_type', 'node')
			->propertyCondition('status', 1)
			->propertyCondition('type', $type)
			->fieldCondition('field_is_reading_challenge', 'value', 1, '=')
			->fieldCondition('field_fry_reading_score', 'value', $min , '>=')
			->fieldCondition('field_fry_reading_score', 'value', $max , '<=')
			->execute();

		if(isset($result['node'])){
			return $result['node'];
		}
		else {
		  drupal_set_message("We're Sorry, it looks like there are no reading challenges that match your grade-level. <br /><br />Please let your teacher know you have received this message. <br /><br />If you feel that you have received this message in error please ask you teacher to contact RIF technical support.");
		  drupal_goto("/literacy-tracker/student/dashboard");
		}
	}

	function _choose_reading_passage_from_list($array, $prefer_new = false) {
		if($prefer_new) {
			$preferred_array = _filter_reading_passage_list($array);
		} else {
			$preferred_array = $array;
		}
		// Given an array of possible reading passages pick a random one;
		return array_rand($preferred_array);
	}

	function _filter_reading_passage_list($array) {
		// TODO: Do some filtering magic to return an array of equaly desirable options for the reading passage
		return $array;
	}

	function _get_guestimated_reading_grade_level() {
		$entity_type = 'reading_challenge';

		global $user;

		$has_challenges = false;

		$query = new EntityFieldQuery;
		$result = $query
			->entityCondition('entity_type', $entity_type)
			->propertyCondition('student_id', $user->uid)
			->propertyOrderBy('created_at', 'DESC')
			->range(0, 10)
			->execute();

		// We only use the 10 most recent reading challenges when guesstimating the users new score.

		if(isset($result['reading_challenge'])){
			$ids = array_keys($result['reading_challenge']);
			$reading_challenges = entity_load($entity_type, $ids);
			if(!empty($reading_challenges)) {
				$has_challenges = true;
			}
		}

		if(!$has_challenges) {
			// Return users current Grade level + 0.5;
			$emw_account = entity_metadata_wrapper('user', $user);
			$reader_profile = profile2_load_by_user($user);

			// Modify users grade level based on teachers above, at, or below setting
			if(isset($reader_profile['literacy_tracker_reader'])){
				$reader_profile_wrapper = $reader_profile['literacy_tracker_reader']->wrapper();

				switch($reader_profile_wrapper->field_reading_at_grade_level->value()) {
					case "Below":
						$grade_value_modifier = 0.2;
						break;
					case "Above":
						$grade_value_modifier = 0.8;
						break;
					case "At Level":
					default:
						$grade_value_modifier = 0.5;
						break;
				}

				$grade_level = $reader_profile_wrapper->field_grade_level->value();
				// Get a rendered value of grade levels to grade values
				$grade_value = intval($grade_level->name);
				return $grade_value+$grade_value_modifier;
			} else { return 3.5; } // This should like... never happen.
		}

		// Use those 10 reading challenges to find average reading grade level
		$total_score = (float) 0;
		$challenge_count = 0;
		foreach($reading_challenges as $index => $reading_challenge) {
//			$reading_challenge->name .= "Updated";
//			$debug_val = entity_save($entity_type, $reading_challenge);
			$current_percentile = $reading_challenge->percentile;
			$current_grade = $reading_challenge->reading_passage_grade_level;
			$current_score = _get_score_from_percentile($current_percentile, $current_grade);
			$total_score += $current_score;
			$challenge_count++;
		}

		$calculated_grade_level = $total_score/$challenge_count;

		//drupal_set_message(t('Calculated Grade Level: @grade_level', array('@grade_level' => $calculated_grade_level)), 'status');

		return $calculated_grade_level;
	}

	function limit_value($value, $min, $max) {
	  return $value < $min ? $min : ($value > $max ? $max : $value);

    }