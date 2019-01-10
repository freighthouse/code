<?php

	function literacy_tracker_edit_user_callback($js = NULL, $user= NULL) {
		$debug_val = true;
		// Code derived from: https://gist.github.com/mrconnerton/1979037
		if ($user == NULL) {
			return 'No UID was sent. Error';
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

		$emw_user = entity_metadata_wrapper( 'user', $user);

		$form_state = array(
			'ajax' => TRUE,
			'title' => t("Edit User {$emw_user->field_first_name->value()} {$emw_user->field_last_name->value()}"),
			'user_id' => $emw_user->uid->value(),
		);
		$form_state['build_info']['args'] = array($emw_user);

		// Use ctools to generate ajax instructions for the browser to create a form in a modal popup.
		$output = ctools_modal_form_wrapper('literacy_tracker_edit_user_form', $form_state);

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
	function literacy_tracker_edit_user_form($form, $form_state, $user_to_edit) {
		
		$emw_user = entity_metadata_wrapper( 'user', $user_to_edit );

		$reader_profile = profile2_load_by_user($user_to_edit->value());
		if (empty($reader_profile)) {
			$reader_profile = profile2_create(array(
				'type' => 'literacy_tracker_reader',
				'uid' => $user_to_edit,
			));
		}

		$emw_profile_wrapper = $reader_profile['literacy_tracker_reader']->wrapper();
		
		// Create a form table that allows user data to be entered
		// ************************************************
		// 		Were ready so lets build the form
		// ************************************************
		$form                = array();
		$form['#attributes'] = array( 'class' => 'lt-add-users-form' );
		
		$form['header'] = array(
			'#markup' => '<h3>Edit Student: </h3>',
		);
		
		$form['user_to_edit_id'] = array(
			'#type'  => 'hidden',
			'#value' => $emw_user->uid->value(),
		);
		
		$form['people'] = array(
			'#prefix' => '<div id="people">',
			'#suffix' => '</div>',
			'#tree'   => true,
			'#theme'  => 'table',
			'#header' => array(
				'',
				'<span class="pull-left req-star">*</span>' . t( 'First name' ),
				t( 'Last Initial' ),
				'<span class="pull-left req-star">*</span>' . t( 'Grade' ),
				'<span class="pull-left req-star">*</span>' . t( 'Reading at Grade Level' ),
				//t( 'Lexile Range' )
			),
			'#rows'   => array(),
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
		);
		//$grade_options            = _vocab_name_to_options_array( 'grade_levels' );
		$reading_at_level_options = list_allowed_values( field_info_field( 'field_reading_at_grade_level' ) );
		//$lexile_range_options     = list_allowed_values( field_info_field( 'field_lexile_range' ) );
		
		for ($i = 0; $i < 1; $i++) {
			// Build the fields for this row in the table. We'll be adding
			// these to the form several times, so it's easier if they are
			// individual variables rather than in an array.

			$first_name       = array(
				'#id'   => 'people-' . $i . '-fname',
				'#type' => 'textfield',
				//'#attributes' => array('placeholder' => t('First Name')),
				'#default_value' => $emw_profile_wrapper->get('field_first_name')->value(),
			);
			$last_initial     = array(
				'#id'        => 'people-' . $i . '-sname',
				'#type'      => 'textfield',
				'#size'      => 6,
				'#maxlength' => 3,
				'#default_value' => $emw_profile_wrapper->get('field_last_initial')->value(),
			);
			$grade            = array(
				'#id'           => 'people-' . $i . '-grade',
				'#type'         => 'select',
				'#empty_option' => 'Choose...',
				'#options'      => $grade_options,
				'#default_value' => $emw_profile_wrapper->get('field_grade_level')->value()->tid,
			);
			$reading_at_level = array(
				'#id'           => 'people-' . $i . '-ral',
				'#type'         => 'select',
				'#empty_option' => 'Choose...',
				'#options'      => $reading_at_level_options,
				'#default_value' => $emw_profile_wrapper->get('field_reading_at_grade_level')->value(),
			);

//			$lexile_range = array(
//				'#id'           => 'people-' . $i . '-lr',
//				'#type'         => 'select',
//				'#empty_option' => 'Choose...',
//				'#options'      => $lexile_range_options,
//				'#default_value' => $emw_profile_wrapper->get('field_lexile_range')->value(),
//			);

			// Include the fields so they'll be rendered and named
			// correctly, but they'll be ignored here when rendering as
			// we're using #theme => table.
			//
			// Note that we're using references to the variables, not just
			// copying the values into the array.

			$form['people'][ $i ] = array(
				"first_name"       => &$first_name,
				"last_initial"     => &$last_initial,
				"grade"            => &$grade,
				"reading_at_level" => &$reading_at_level,
				//"lexile_range"     => &$lexile_range,
			);

			// Now add references to the fields to the rows that
			// `theme_table()` will use.
			//
			// As we've used references, the table will use the very same
			// field arrays as the FAPI used above.

			$form['people']['#rows'][] = array(
				array( 'data' => $i + 1 ),
				array( 'data' => &$first_name ),
				array( 'data' => &$last_initial ),
				array( 'data' => &$grade ),
				array( 'data' => &$reading_at_level ),
				//array( 'data' => &$lexile_range ),
			);

			// Because we've used references we need to `unset()` our
			// variables. If we don't then every iteration of the loop will
			// just overwrite the variables we created the first time
			// through leaving us with a form with 3 copies of the same fields.

			unset( $first_name );
			unset( $last_initial );
			unset( $grade );
			unset( $reading_at_level );
			//unset( $lexile_range );
		}
	

		$form['actions'] = array(
			'#type' => 'fieldset',
			'#attributes' => array('class' => array('modal-actions')),
		);
		
		$form['actions']['cancel'] = array(
			'#type' => 'submit',
			'#value' => t('Cancel'),
			'#attributes' => array('class' => array('btn btn-red pull-left')),
			'#submit' => array('literacy_tracker_edit_user_form_cancel'),
		);

		$form['actions']['submit'] = array(
			'#type' => 'submit',
			'#value' => t('Save Changes'),
			'#attributes' => array(
				'class' => array('btn btn-blue btn-add-material-all pull-right'),
			),
		);

		return $form;
	}

	function literacy_tracker_edit_user_form_validate(&$form, &$form_state) {
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
					// Any needed validation checks about that user.
				}
			}
		}
		$form_state['answered_indexes'] = $answered_indexes;
	}
	
	function literacy_tracker_edit_user_form_cancel(&$form, &$form_state) {
		$form_state['ajax_commands'][] = ctools_modal_command_dismiss();
	}
	
	function literacy_tracker_edit_user_form_submit(&$form, &$form_state)
	{
//		$reading_group_node = $form_state['reading-group-nid'];
//		$emw_book = entity_metadata_wrapper('node', $reading_group_node);
		$user_id_to_edit = $form_state['values']['user_to_edit_id'];
		$account = user_load($user_id_to_edit);
		$emw_account = entity_metadata_wrapper('user', $user_id_to_edit);

		$current_values = $form_state['values']['people'][0];

		// Using the 5 column fields update the current user for each of the fields.
		$current_first_name = $current_values['first_name'];
		$current_last_initial = $current_values['last_initial'];
		$current_grade_level = $current_values['grade'];
		$current_reading_at_grade_level = $current_values['reading_at_level'];
		$current_lexile_range = $current_values['lexile_range'];

		// TODO: Convert Lexile Range to the average value of that range to start off.
		$current_guesstimated_lexile_level = 50;

		// Convert Username to Lowercase and underscores
		$current_user_name_converted = strtolower(str_replace(' ', '', trim($current_first_name)));

		/*$newUser = array(
			'name' => $current_user_name_converted,
			'pass' => $password,  // note: do not md5 the password
			'mail' => "literacy_tracker.{$current_user_name_converted}@no-reply.com",
			'status' => 1,
			'init' => 'email address',
			'roles' => array(
				DRUPAL_AUTHENTICATED_RID => 'authenticated user',
				12 => 'lt_reader', // role id for custom roles varies per website
			),
		);

		$account = user_save(null, $newUser);*/

		//save additional main account fields
		$emw_account->field_first_name = $current_first_name;
		$emw_account->field_last_name = $current_last_initial;
		$emw_account->field_state = 'other';
		$emw_account->field_zip = '00000';
		$emw_account->name = $current_user_name_converted.$account->uid;
		$emw_account->save();

		$reader_profile = profile2_load_by_user($account);
		if (empty($reader_profile)) {
			$reader_profile = profile2_create(array(
				'type' => 'literacy_tracker_reader',
				'uid' => $account->uid,
			));
		}

		// Set the reader profile data
		$profile_wrapper = $reader_profile['literacy_tracker_reader']->wrapper();
		$profile_wrapper->field_first_name = $current_first_name;
		$profile_wrapper->field_last_initial = $current_last_initial;
		$profile_wrapper->field_grade_level = $current_grade_level;
		$profile_wrapper->field_reading_at_grade_level = $current_reading_at_grade_level;
		// TODO: Current lexile range seems to not be saving correctly... This is going away though so let's not worry about it now.
		$profile_wrapper->field_lexile_range = $current_lexile_range;
		$profile_wrapper->field_guesstimated_lexile_level = $current_guesstimated_lexile_level;

		$profile_wrapper->save();

		drupal_set_message("You have successfully edited {$current_first_name}\'s details");
	}

	function _vocab_name_to_options_array($vocabulary_name) {
		$toReturn = array();
		$terms = taxonomy_get_tree(taxonomy_vocabulary_machine_name_load($vocabulary_name)->vid);

		foreach($terms as $data) {
			$toReturn[$data->tid] = $data->name;
		}

		return $toReturn;
	}