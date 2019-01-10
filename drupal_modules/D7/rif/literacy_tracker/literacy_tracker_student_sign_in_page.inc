<?php
	function get_sign_in_page_lt() {
		global $user;
		module_load_include('pages.inc', 'user');
		
		// TODO: Unncomment out these lines as they are not included for testing.
		// If the user has a specific role send the user to the correct page
		$lt_reader_id = array_search('LT Reader', user_roles());
		if(!user_has_role($lt_reader_id)) {
			user_logout_current_user();
		};
		if(user_has_role(6)){
            user_logout_current_user();
			//drupal_goto('literacy-central/my-account');
		} elseif(user_has_role(8)) {
            user_logout_current_user();
			//drupal_goto('literacy-network/my-account');
		} elseif(user_has_role($lt_reader_id)) {
			drupal_goto('literacy-tracker/student/dashboard');
		}

		// If this is an auth user, lets send them to the literacy-tracker main page
		/*if(!user_is_anonymous()) {
			drupal_goto('literacy-tracker/main');
		}*/

		// if the user is anonymous then lets let them login as a student
		$form = drupal_get_form('user_login_block');

		$form_html = drupal_render($form);

		$content = theme('literacy_tracker__front_page', array('sign_in_form'=>$form_html));
		/*$content['raw_markup'] = array(
			'#type' => 'markup',
			'#markup' => $form_html,
		);*/

		return $content;
	}
