<?php

	function multi_profile_form($form, &$form_state) {
		$form['rif_registration_settings_form'] = array(
			'#type' => 'radios',
			'#title' => t('Multi-Profile Settings'),
			'#options' => array('302'=> t('Default Campaign'), '304'=> t('Test Override')),
			'#default_value' => variable_get('content_bundles_default_campaign (TODO)'),
			'#description' => t('Set the default content campaign'),
		);

		return(system_settings_form($form));
	}