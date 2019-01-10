<?php
	/**
	 * @file
	 * User Profile2 MYPROFILE2TYPE.
	 */

	function get_my_account_page() {
		$toReturn = "";

		if(user_is_anonymous()){
			drupal_goto('user/sign-in');
		}

		global $user;
		//dsm($user);
		$user = user_load($user->uid);
		// Loading the module to have access to the form.

		$my_account_form = drupal_get_form('rif_registration_load_my_account_form', $user);
		$toReturn .= drupal_render($my_account_form);

		$content['raw_markup'] = array(
			'#type' => 'markup',
			'#markup' => $toReturn,
		);
		return $content;
	}

	function get_my_account_page_lc() {
		$toReturn = "";

		if(user_is_anonymous()){
			drupal_goto('literacy-central/sign-in');
		}

		global $user;
		//dsm($user);
		$user = user_load($user->uid);
		// Loading the module to have access to the form.

		$my_account_form = drupal_get_form('rif_registration_load_my_account_form', $user);
		$toReturn .= drupal_render($my_account_form);

		$block = module_invoke('content_bundles', 'block_view', 'rif_back_nav');

		$toReturn = '<div class="container panel-push-down">'. $toReturn . '</div>';

		$toReturn = render($block['content']) . $toReturn;

		$content['raw_markup'] = array(
			'#type' => 'markup',
			'#markup' => $toReturn,
		);
		return $content;
	}

	function get_my_account_page_ln() {
		$toReturn = "";

		if(user_is_anonymous()){
			drupal_goto('literacy-network/sign-in');
		}

		global $user;
		//dsm($user);
		$user = user_load($user->uid);
		// Loading the module to have access to the form.

		$my_account_form = drupal_get_form('rif_registration_load_my_account_form', $user);
		$toReturn .= drupal_render($my_account_form);

		$toReturn = '<div class="container panel-push-down">'. $toReturn . '</div>';

		$content['raw_markup'] = array(
			'#type' => 'markup',
			'#markup' => $toReturn,
		);
		return $content;
	}

	function rif_registration_load_my_account_form($form, &$form_state, $user = NULL) {
		//TODO Don't load the my account form unless the $user exists
		//dsm($form_state);
		$form = [];

		/*$form['header'] = array(
			"#markup" => $user->name . " Accounts Page",
			'#prefix' => '<h1>',
			'#suffix' => '</h1>',
			'#weight' => '-100',
		);*/
		$form['actions'] = array(
			'type' => 'container',
			'#weight' => '100',
		);

		$types = profile2_get_types();

		// We take care of profiles weights.
		usort($types, 'account_profile_sort_profile_by_weight');

		$profile = [];

		global $user;
		$user = user_load($user->uid);
		/* ============================================================ *
		 * 					Create Users Drupal Profile 				*
		 * ============================================================ */
		// Loading the module to have access to the form.
		module_load_include('inc', 'user', 'user.pages');
		$form = user_profile_form($form, $form_state, $user);
		$form['account']['#type'] = 'fieldset';
		$form['account']['#title'] = t('My Account');
		$form['account']['#collapsible'] = FALSE;
		$form['account']['#collapsed'] = FALSE;

		// Prepend #pre_render callback to rearrange form fields
		if (!isset($form['#pre_render'])) {
			$form['#pre_render'] = array();
		}
		array_unshift($form['#pre_render'], 'rearrange_form_elements');

		//dsm('userProfileForm');
		//dsm($form);

		/* ============================================================ *
		 * 					Build Users LC Profile 					*
		 * ============================================================ */

		$lc_id = 'literacy_central';
		$lc_role = user_role_load_by_name('literacy user');
		$has_lc_role = user_has_role($lc_role->rid);
		$profile[$lc_id] = profile2_load_by_user($user, $lc_id);

		if(empty($profile[$lc_id])) {
			//dsm("No LC Profile Found");
			$profile[$lc_id] = profile_create(array('type' => $lc_id, 'uid' => $user->uid));
		}

		//dsm($lc_role);
		if($has_lc_role) {
//			dsm("User has the LC role");
		} else {
//			dsm("User doesn't have the lc role... //TODO Style the opt-in buttons
			$form['LC_opt_in'] = array(
				'#type' => 'checkbox',
				'#title' => t('Opt-In to Literacy Central?'),
				'#attributes' => array('class' => array('lc-opt-in')),
				'#options' => array(0 => t('Closed'), 1 => t('Active')),
				'#default_value' => 0,
				'#states' => array(
					'invisible' => array(
						':input[name="LC_opt_in"]' => array('checked' => TRUE),
					)
				),
				'#prefix' => '<div class="row"><div class="col-xs-12"><div class="btn btn-opt-in btn-blue">',
				'#suffix' => '</div></div></div>',
			);
			$form['#submit'][] = 'rif_registration_add_literacy_central_role';
		}

		if (profile2_access('edit', $profile[$lc_id], $user)) {
			if (!isset($form_state["profiles"])) {
				$form_state["profiles"] = array();
			}
			$form_state['profiles'][$profile[$lc_id]->type] = $profile[$lc_id];
			profile2_attach_form($form, $form_state);
			$form['profile_' . $lc_id] += array(
				'#type' => 'fieldset',
				'#title' => check_plain($profile[$lc_id]->getTranslation('label')),
				'#states' => array(
					'visible' => array(
						':input[name="LC_opt_in"]' => array('checked' => TRUE),
					)
				),
			);
		}

		/* ============================================================ *
		 * 					Build Users LN Profile 						*
		 * ============================================================ */
		$ln_id = 'literacy_network';
		$ln_role = user_role_load_by_name('Community Member');
		$has_ln_role = user_has_role($ln_role->rid);
		$profile[$ln_id] = profile2_load_by_user($user, $ln_id);

		if(empty($profile[$ln_id])) {
			//dsm("No LC Profile Found");
			$profile[$ln_id] = profile_create(array('type' => $ln_id, 'uid' => $user->uid));
		}

		if($has_ln_role) {
			//dsm("User has the LN role");
		} else {
			//dsm("User doesn't have the ln role...");
			$form['LN_opt_in'] = array(
				'#type' => 'checkbox',
				'#title' => t('Opt-In to Literacy Network?'),
				'#attributes' => array('class' => 'ln-opt-in'),
				'#options' => array(0 => t('Closed'), 1 => t('Active')),
				'#default_value' => 0,
				'#states' => array(
					'invisible' => array(
						':input[name="LN_opt_in"]' => array('checked' => TRUE),
					)
				),
				'#prefix' => '<div class="row"><div class="col-xs-12"><div class="btn btn-opt-in btn-blue">',
				'#suffix' => '</div></div></div>',
			);
			$form['#submit'][] = 'rif_registration_add_literacy_network_role';
		}

		$form['#validate'][] = 'validate_literacy_network_role';

		if(profile2_access('edit', $profile[$ln_id], $user)) {
			if(!isset($form_state)) {
				$form_state["profiles"] = array();
			}
			$form_state['profiles'][$profile[$ln_id]->type] = $profile[$ln_id];
			profile2_attach_form($form, $form_state);
			$form['profile_' . $ln_id] += array(
				'#type' => 'fieldset',
				'#title' => check_plain($profile[$ln_id]->getTranslation('label')),
				'#states' => array(
					'visible' => array(
						':input[name="LN_opt_in"]' => array('checked' => TRUE),
					)
				),
			);
			$form['profile_' . $ln_id]['field_community_user_type']['und']['#required'] = FALSE;
//			$form['profile_' . $ln_id]['field_community_user_type'] += array(
//				'#states' => array(
//					'required' => array(
//						':input[name="LN_opt_in"]' => array('checked' => TRUE),
//					)
//				),
//			);
			//dsm($form);
		}

		/* ============================================================ *
		 * 					Attach newsletter preferences				*
		 * ============================================================ */

		global $user;
		$uid = $user->uid;
		if($uid === 0) {
			// An anonymous user is somehow editing a profile form. Lets bail.
			watchdog('rif_registration', 'An anonymous user is somehow editing a profile form.', NULL, WATCHDOG_ERROR);
		}
		//Check if this user has a newsletter preferences node yet.
		$type = 'newsletter_signup';
		$query = new EntityFieldQuery;
		$result = $query
			->entityCondition('entity_type', 'node')
			->propertyCondition('status', 1)
			->propertyCondition('type', $type)
			->propertyCondition('uid', $uid)
			->execute();

		if(sizeof($result) > 1) {
			watchdog('rif_registration', 'A user (UID:%uid) has more than one newsletter preference.', array('%uid' => $uid), WATCHDOG_ERROR);
		}

		$getRIFNewsletterDefault = TRUE;
		$getLCNewsletterDefault = FALSE;
		$getLNNewsletterDefault = FALSE;
		if(!empty($result)) {
			//even if a user has more than one newsletter lets grab the first one.
			$newsletter_node_nid = array_values($result['node'])[0]->nid;
			// Load the node so we can grab the current setting values ( Use EMW for ease of use )
			$emw_node = entity_metadata_wrapper('node', $newsletter_node_nid);

			//Grab the current values and set the defaults to them
			$getRIFNewsletterDefault = $emw_node->field_get_rif_newsletter->value();
			/*$getLCNewsletterDefault = $emw_node->field_get_lc_newsletter->value();
			$getLNNewsletterDefault = $emw_node->field_get_ln_newsletter->value();*/
		}

		$form['newsletter_preferences'] = array(
			'#type' => 'fieldset',
			'#title' => t('Newsletter Preferences'),
			'#collapsible' => FALSE,
			'#collapsed' => FALSE,
		);

		$form['newsletter_preferences']['field_get_rif_newsletter'] = array(
			'#type' => 'checkbox',
			'#title' => t('Get the RIF Newsletter'),
			'#attributes' => array('class' => array('newsletter-option')),
			'#options' => array(0 => t('Closed'), 1 => t('Active')),
			'#default_value' => $getRIFNewsletterDefault,
		);
		/*$form['newsletter_preferences']['field_get_lc_newsletter'] = array(
			'#type' => 'checkbox',
			'#title' => t('Get the Literacy Central Newsletter'),
			'#attributes' => array('class' => array('newsletter-option')),
			'#options' => array(0 => t('Closed'), 1 => t('Active')),
			'#default_value' => $getLCNewsletterDefault,
		);
		$form['newsletter_preferences']['field_get_ln_newsletter'] = array(
			'#type' => 'checkbox',
			'#title' => t('Get the Literacy Network Newsletter'),
			'#attributes' => array('class' => array('newsletter-option')),
			'#options' => array(0 => t('Closed'), 1 => t('Active')),
			'#default_value' => $getLNNewsletterDefault,
		);*/

		$form['#submit'][] = 'rif_registration_update_newsletter';

		/* ============================================================ *
		 * 					Setup Action Buttons						*
		 * ============================================================ */

		$form['actions']['submit'] += array(
			'#type' => 'submit',
			'#attributes' => array(
				'class' => array(
				  'btn btn-yellow-rif blue-border'
				),
			  ),
			//'#attributes' => array('class' => array('btn btn-blue')),
			'#value' => t('Update'),
		);

		$form['actions']['cancel'] = array(
			'#type' => 'submit',
			'#value' => t('Cancel Changes'),
			'#attributes' => array(
				'class' => array(
				  'btn btn-yellow-rif blue-border'
				),
			  ),
			//'#attributes' => array('class' => array('btn btn-red')),
			'#submit' => array('rif_registration_load_my_account_cancel'),
		);
		return $form;
	}

	// Form Validation Functions

	function validate_literacy_network_role($form, &$form_state){
		$responses = $form_state['values'];
		//dsm("Enter Form Validation Function");
		//dsm($form_state);
		if(array_key_exists('LC_opt_in', $responses) && !$responses['LC_opt_in']) {
			//dsm("Don't validate LC form fields");
		} else {
			//dsm("Validate LC form fields");
		}
		if(array_key_exists('LN_opt_in', $responses) && !$responses['LN_opt_in']) {
			//dsm("Don't validate Network form fields");
		} else {
			$community_user_type_response = $responses['profile_literacy_network']['field_community_user_type']['und'];
			if(array_filter($community_user_type_response[0])) { //Check if there are any user types in an array
				//dsm('community response has a value');
			} else {
				// Network Form is available but Community User Type does not have a choice selected
				//form_set_error('LN_opt_in', t("Please select a community user type"));
			}
		}
	}

	// Form Submission Functions

	function rif_registration_update_newsletter($form, &$form_state) {
		//Find the users newsletter node
		global $user;
		$uid = $user->uid;
		if($uid === 0) {
			watchdog('rif_registration', 'An anonymous user is somehow submiting a profile form.', NULL, WATCHDOG_ERROR);
		}
		$type = 'newsletter_signup';
		$query = new EntityFieldQuery;
		$result = $query
			->entityCondition('entity_type', 'node')
			->propertyCondition('status', 1)
			->propertyCondition('type', $type)
			->propertyCondition('uid', $uid)
			->execute();

		if(sizeof($result) > 1 && $uid !== 0) {
			watchdog('rif_registration', 'A user (UID:%uid) has more than one newsletter preference.', array('%uid' => $uid), WATCHDOG_ERROR);
		}

		if(empty($result)) {
			//On the off chance the user doesn't have an associated newsletter node - make one (Create new Node and get nid)
			// Create an Entity.
			$node = entity_create('node', array('type' => 'newsletter_signup'));
			// Specify the author.
			$node->uid = $user->uid;
			// Create a Entity Wrapper of that new Entity.
			$emw_node = entity_metadata_wrapper('node', $node);
			// Set a title
			$emw_node->title = 'newsletter_signup_from_account';
			// And save it.
			$emw_node->save();
		} else {
			//even if a user has more than one newsletter lets grab the first one.
			$newsletter_node_nid = array_values($result['node'])[0]->nid;
			// Load the node so we can grab the current setting values ( Use EMW for ease of use )
			$emw_node = entity_metadata_wrapper('node', $newsletter_node_nid);
		}

		//Set the from values to update the node.
		$emw_node->field_first_name->set($form_state['values']['field_first_name'][LANGUAGE_NONE][0]['value']);
		$emw_node->field_last_name->set($form_state['values']['field_last_name'][LANGUAGE_NONE][0]['value']);
		$emw_node->field_email->set($form_state['values']['mail']);
		$emw_node->field_get_rif_newsletter->set($form_state['values']['field_get_rif_newsletter']);
		/*$emw_node->field_get_lc_newsletter->set($form_state['values']['field_get_lc_newsletter']);
		$emw_node->field_get_ln_newsletter->set($form_state['values']['field_get_ln_newsletter']);*/
		$emw_node->save();
	}

	function rif_registration_load_my_account_cancel() {
		dsm("Canceled Updates");
		$form_state['redirect'] = '';
	}

	function rif_registration_add_literacy_central_role($form, &$form_state) {
		if($form_state['values']['LC_opt_in'] == 1) {
			global $user;
			$role = user_role_load_by_name("literacy user");
			user_multiple_role_edit(array($user->uid), 'add_role', $role->rid);
		}
	}
	function rif_registration_add_literacy_network_role($form, &$form_state) {
		if($form_state['values']['LN_opt_in'] == 1) {
			global $user;
			$role = user_role_load_by_name("Community Member");
			user_multiple_role_edit(array($user->uid), 'add_role', $role->rid);
			//user_save($user); // WTF: (If this is not commented out then the user for some reason gets EVERY USER ROLE!!! WTF!
		}
	}

	// Helper Functions

	/**
	 * Helper to sort profiles based on weight prop.
	 *
	 * @param ProfileType $a
	 *   a profile
	 * @param ProfileType $b
	 *   a profile
	 *
	 * @return bool
	 *   int
	 *
	 * Example usage:
	 * @code
	 * $types = profile2_get_types();
	 * usort($types, '_sort_profile_by_weight');
	 * @endcode
	 */
	function account_profile_sort_profile_by_weight($a, $b) {
		return $a->weight == $b->weight ? 0 : ($a->weight > $b->weight) ? 1 : -1;
	}