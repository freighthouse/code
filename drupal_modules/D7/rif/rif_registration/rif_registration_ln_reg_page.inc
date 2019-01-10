<?php

	function get_registration_page_ln() {
		$toReturn = "";
		$ln_id = 'literacy_network';

		//$form = drupal_get_form('rif_registration_ln_register_form');

		$form = drupal_get_form('user_register_form');

		$jumbo_node_html = node_view(node_load(5066));

		$back_nav_block = module_invoke('content_bundles', 'block_view', 'rif_panel_separator');
		$header_markup = render($back_nav_block['content']);

		$toReturn = '<div class="header">'.render($jumbo_node_html).'</div>'.$header_markup.'
<div class="container panel-push-down">'. drupal_render($form) . '</div>
';

		$content['raw_markup'] = array(
			'#type' => 'markup',
			'#markup' => $toReturn,
		);
		return $content;
	}

	function rif_registration_ln_register_form($form, &$form_state) {
		$form = [];
		$ln_id = 'literacy_network';

		//dsm($registration_form);

		$form = user_register_form($form, $form_state);
		if (empty($form_state['profiles'][$ln_id])) {
			$form_state['profiles'][$ln_id] = profile2_create(array('type' => $ln_id));
		}
		profile2_attach_form($form, $form_state);

		return $form;
	}

		/*$form['header'] = array(
			"#markup" => "Register a new Literacy Network Account",
			'#prefix' => '<h1>',
			'#suffix' => '</h1>',
			'#weight' => '-100',
		);

		$form['account_description'] = array(
			"#markup" => "Registering for a literacy network account will connect you with a professional community of educators, parents, and volunteers with the single focus of advancing literacy throughout the nation and worldwide. Join today to be a part of this great undertaking",
			'#prefix' => '<p>',
			'#suffix' => '</p>',
			'#weight' => '-90',
		);

		if (empty($form_state['profiles'][$ln_id])) {
			$form_state['profiles'][$ln_id] = profile2_create(array('type' => $ln_id));
		}
		profile2_attach_form($form, $form_state);
		// Wrap LN profile form in a fieldset.
		$form['profile_' . $ln_id] += array(
			'#type' => 'fieldset',
			'#title' => "Literacy Network",
		);

		$form['profile_literacy_network']['field_phone_number'] += array(
			'#states' => array(
				'visible' => array(
					':input[name="profile_literacy_network[field_community_user_type][und]"]' => array('value' => '959'),
				),
				'required' => array(
					':input[name="profile_literacy_network[field_community_user_type][und]"]' => array('value' => '959'),
				),
			),
		);
		$form['profile_literacy_network']['field_volunteer_interest'] += array(
			'#states' => array(
				'visible' => array(
					':input[name="profile_literacy_network[field_community_user_type][und]"]' => array('value' => '959'),
				),
			),
		);

		$form['#validate'][] = 'validate_literacy_network_role';

		/*
		 * $form['#submit'][] = 'add_literacy_network_role';
		 * */

/*
		dsm($form);

		return $form;
	}*/

/*	// Validate LN Registration
	function validate_literacy_network_role($form, &$form_state){
		$responses = $form_state['values'];
		dsm("Enter Form Validation Function");
		dsm($form_state);
		dsm($responses);

		form_set_error('profile_literacy_network[field_community_user_type][und]', t("Fail all validation while under development"));
	}*/