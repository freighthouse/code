<?php

	function rif_advanced_feeds_form($form, &$form_state) {

		$form['rif_advanced_feeds_general_error'] = array(
			'#type' => 'textfield',
			'#title' => t('General Import Error Message'),
			'#default_value' => variable_get('rif_advanced_feeds_general_error'),
			'#description' => t('The general message when an importer finds an error'),
		);

		$form['rif_advanced_feeds_missing_columns_error'] = array(
			'#type' => 'textfield',
			'#title' => t('Missing Columns Message'),
			'#default_value' => variable_get('rif_advanced_feeds_missing_columns_error'),
			'#description' => t('The message to display indicating that columns are missing for an importer.'),
		);

		$form['rif_advanced_feeds_extra_columns_error'] = array(
			'#type' => 'textfield',
			'#title' => t('Extra Columns Message'),
			'#default_value' => variable_get('rif_advanced_feeds_extra_columns_error'),
			'#description' => t('The message to display indicating that importer has found extra columns.'),
		);

		return(system_settings_form($form));
	}