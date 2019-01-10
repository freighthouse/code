<?php

	function literacy_tracker_add_users_multiple_callback($js = NULL, $node_to_edit = NULL) {
		// TODO: Check that the current user is the same as the author of the node to edit
		global $user;

		// Code derived from: https://gist.github.com/mrconnerton/1979037
		if ($node_to_edit == NULL) {
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

		module_load_include('inc', 'node', 'node.pages');

		ctools_include('ajax');
		ctools_include('modal');

		$form_state = array(
			'ajax' => TRUE,
			'title' => t("Add Students to {$node_to_edit->field_group_name['und'][0]['value']}"),
			'reading-group-nid' => $node_to_edit->nid,
		);
		$form_state['build_info']['args'] = array($node_to_edit);

		// Use ctools to generate ajax instructions for the browser to create a form in a modal popup.
		$output = ctools_modal_form_wrapper('literacy_tracker_add_multiple_users_form', $form_state);

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

	/* ****************************************
	 * 			Add Multiple Users Form
	 * **************************************** */
	function literacy_tracker_add_multiple_users_form($form, $form_state, $reading_group_node)
	{

		$emw_reading_group = entity_metadata_wrapper('node', $reading_group_node);

		// Create a form table that allows user data to be entered
		// ************************************************
		// 		Were ready so lets build the form
		// ************************************************
		$form = array();
		$form['#attributes'] = array('class' => 'lt-add-users-form');

		$form['header'] = array(
			'#markup' => '<h3>'.$reading_group_node->field_group_name['und'][0]['value'].'<span class="pull-right table-instructions">You can add 10 students at a time.</span></h3>',
		);

		$form['reading_group_node'] = array(
			'#type' => 'hidden',
			'#value' => $reading_group_node->nid,
		);

		$form['people'] = array(
			'#prefix' => '<div id="people">',
			'#suffix' => '</div>',
			'#tree' => TRUE,
			'#theme' => 'table',
			'#header' => array('', '<span class="pull-left req-star">*</span>' . t('First name'), t('Last Initial'), '<span class="pull-left req-star">*</span>' . t('Grade'), '<span class="pull-left req-star">*</span>' . t('Estimated Reading Level')),
			'#rows' => array(),
		);

		// Create our table of elements
		$grade_options = array(
//          2063 => "Pre-K",
//          71 => "K",
          243 => "1st",
          65 => "2nd",
          72 => "3rd",
          449 => "4th",
          244 => "5th",
          554 => "6th",
        );//_vocab_name_to_options_array('grade_levels');
		$reading_at_level_options = list_allowed_values(field_info_field('field_reading_at_grade_level'));
		//$lexile_range_options = list_allowed_values(field_info_field('field_lexile_range'));

		for ($i = 0; $i < 10; $i++) {
			// Build the fields for this row in the table. We'll be adding
			// these to the form several times, so it's easier if they are
			// individual variables rather than in an array.

			$first_name = array(
				'#id' => 'people-' . $i . '-fname',
				'#type' => 'textfield',
				//'#attributes' => array('placeholder' => t('First Name')),
			);
			$last_initial = array(
				'#id' => 'people-' . $i . '-sname',
				'#type' => 'textfield',
				'#size' => 6,
				'#maxlength' => 3,``
			);
			$grade = array(
				'#id' => 'people-' . $i . '-grade',
				'#type' => 'select',
				'#empty_option' => '----',
				'#options' => $grade_options,
			);
			$reading_at_level = array(
				'#id' => 'people-' . $i . '-ral',
				'#type' => 'select',
				'#empty_option' => 'Choose...',
				'#options' => $reading_at_level_options,
			);

//			$lexile_range = array(
//				'#id' => 'people-' . $i . '-lr',
//				'#type' => 'select',
//				'#empty_option' => 'Choose...',
//				'#options' => $lexile_range_options,
//			);

			// Include the fields so they'll be rendered and named
			// correctly, but they'll be ignored here when rendering as
			// we're using #theme => table.
			//
			// Note that we're using references to the variables, not just
			// copying the values into the array.

			$form['people'][$i] = array(
				"first_name" => &$first_name,
				"last_initial" => &$last_initial,
				"grade" => &$grade,
				"reading_at_level" => &$reading_at_level,
				//"lexile_range" => &$lexile_range,
			);

			// Now add references to the fields to the rows that
			// `theme_table()` will use.
			//
			// As we've used references, the table will use the very same
			// field arrays as the FAPI used above.

			$form['people']['#rows'][] = array(
				array('data' => $i + 1),
				array('data' => &$first_name),
				array('data' => &$last_initial),
				array('data' => &$grade),
				array('data' => &$reading_at_level),
				//array('data' => &$lexile_range),
			);

			// Because we've used references we need to `unset()` our
			// variables. If we don't then every iteration of the loop will
			// just overwrite the variables we created the first time
			// through leaving us with a form with 3 copies of the same fields.

			unset($first_name);
			unset($last_initial);
			unset($grade);
			unset($reading_at_level);
			//unset($lexile_range);
		}

		$form['actions'] = array(
			'#type' => 'fieldset',
			'#attributes' => array('class' => array('modal-actions')),
		);

		$form['actions']['submit'] = array(
			'#type' => 'submit',
			'#value' => t('Add Students to Group'),
			'#attributes' => array(
				'class' => array('btn btn-blue btn-add-material-all'),
			),
		);

		return $form;
	}

	function literacy_tracker_add_multiple_users_form_validate(&$form, &$form_state) {
		$answered_indexes = array();
		foreach ($form_state['values']['people'] as $index => $responses) {
			if (($responses['first_name'] != "") || ($responses['last_initial'] != "") || ($responses['grade'] != "") || ($responses['reading_at_level'] != "") || ($responses['lexile_range'] != "")) {
				$answered_indexes[] = $index;
				if ($responses['first_name'] == "" || $responses['grade'] == "" || $responses['reading_at_level'] == "") {
					form_set_error("people][{$index}][general", "Please fill in the required missing fields for Row " . ($index + 1));
					if ($responses['first_name'] == "") {
						form_set_error("people][{$index}][first_name", '');
					}
					if ($responses['grade'] == "") {
						form_set_error("people][{$index}][grade", '');
					}
					if ($responses['grade'] == "") {
						form_set_error("people][{$index}][reading_at_level", '');
					}
				} else {
					// TODO: Any needed validation checks about that user.
				}
			}
		}
		$form_state['answered_indexes'] = $answered_indexes;
	}

	function literacy_tracker_add_multiple_users_form_submit(&$form, &$form_state)
	{
//		$reading_group_node = $form_state['reading-group-nid'];
//		$emw_book = entity_metadata_wrapper('node', $reading_group_node);
		$emw_reading_group = entity_metadata_wrapper('node', $form_state['values']['reading_group_node']);

		//$json_user_data = '';
		$new_user_ids = array();
		// TODO: Get user data from $emw_reading_group
		if(empty($emw_reading_group->field_user_metadata->value())){
			$user_details = (object) array();
		} else {
			$user_details = json_decode($emw_reading_group->field_user_metadata->value());
		}

        $raw_password_options = variable_get('literacy_tracker_password_list');
        $passwords_formatted = $raw_password_options['value'];
        $passwords_formatted = strip_tags($passwords_formatted);
        //$passwords_formatted = str_replace([' '], '', $passwords_formatted);
        $passwords_formatted = str_replace(['_', '.', ';', '&nbsp'], ' ', $passwords_formatted);
        $passwords_formatted =  preg_replace('!\s+!', '', $passwords_formatted);
        $passwords_formatted =  trim($passwords_formatted, " ,\t\n\r\0\x0B");
        $passwords = explode(',', $passwords_formatted);

		foreach($form_state['answered_indexes'] as $response_index) {
			$current_values = $form_state['values']['people'][$response_index];

			// Using the 5 column fields create a new user for each of the fields.
			$current_first_name = $current_values['first_name'];
			$current_last_initial = $current_values['last_initial'];
			$current_grade_level = $current_values['grade'];
			$current_reading_at_grade_level = $current_values['reading_at_level'];
			//$current_lexile_range = $current_values['lexile_range'];

			// TODO: Convert Lexile Range to the average value of that range to start off.
			$current_guesstimated_lexile_level = 50;

			// Convert Username to Lowercase and underscores
			$current_user_name_converted = strtolower(str_replace(' ', '', trim($current_first_name)));

			//Generate a random password from the admin provided list of words.
			//$password = user_password(8);
            $password = $passwords[array_rand($passwords)];
			$lt_reader_id = array_search('LT Reader', user_roles());
            $temp_id = db_next_id(db_query('SELECT MAX(uid) FROM {users}')->fetchField());
			$newUser = array(
				'name' => $current_user_name_converted . "_temp_ID({$temp_id})",
				'pass' => $password,  // note: do not md5 the password
				'mail' => "literacy_tracker.{$current_user_name_converted}@no-reply.com",
				'status' => 1,
				'init' => 'email address',
				'roles' => array(
					DRUPAL_AUTHENTICATED_RID => 'authenticated user',
					$lt_reader_id => 'lt_reader', // role id for custom roles varies per website
				),
			);

			$account = user_save(null, $newUser);

			$emw_account = entity_metadata_wrapper('user', $account);

			//save additional main account fields
			$emw_account->field_first_name = $current_first_name;
			$emw_account->field_last_name = $current_last_initial;
			$emw_account->field_state = 'other';
			$emw_account->field_zip = '00000';
			$emw_account->name = $current_user_name_converted.$account->uid;
			$emw_account->save();

			$new_user_ids[] = $account->uid;
			$user_details->{$account->uid} = (object) array(
				'uid' => $account->uid,
				'username' => $emw_account->name->value(),
				'password' => $password,
			);

			$reader_profile = profile2_load_by_user($account);
			if (empty($reader_profile)) {
				$reader_profile = profile2_create(array(
					'type' => 'literacy_tracker_reader',
					'uid' => $account->uid,
				));
			}

			// Set the reader profile data
			$reader_profile->wrapper()->field_first_name = $current_first_name;
			$reader_profile->wrapper()->field_last_initial = $current_last_initial;
			$reader_profile->wrapper()->field_grade_level = $current_grade_level;
			$reader_profile->wrapper()->field_reading_at_grade_level = $current_reading_at_grade_level;
			
			//$reader_profile->wrapper()->field_lexile_range = $current_lexile_range;
			$reader_profile->wrapper()->field_guesstimated_lexile_level = $current_guesstimated_lexile_level;

			$reader_profile->wrapper()->save();
		}

		// Add all of the new users to the user list (field_associated_users)
		foreach($new_user_ids as $index => $new_uid) {
			$emw_reading_group->field_associated_users[] = $new_uid;
		}
		$json_user_data = json_encode($user_details);
		$emw_reading_group->field_user_metadata = $json_user_data;
		$emw_reading_group->save();

		// get the number of created users.
		$user_count = count($new_user_ids);
		drupal_set_message("You have successfully registered {$user_count} students");

		// TODO: save the created users data as a json field to the reading group
	}

	function _vocab_name_to_options_array($vocabulary_name) {
		$toReturn = array();
		$terms = taxonomy_get_tree(taxonomy_vocabulary_machine_name_load($vocabulary_name)->vid);

		foreach($terms as $data) {
			$toReturn[$data->tid] = $data->name;
		}

		return $toReturn;
	}