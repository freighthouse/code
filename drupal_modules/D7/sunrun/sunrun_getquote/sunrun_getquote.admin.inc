<?php

/**
 * General settings form
 */ 
function sunrun_getquote_settings_form(){
	$form['general'] = array(
		'#title' => t('General'),
		'#type' => 'fieldset',
		'#collapsible' => TRUE,
		'#collapsed' => TRUE
	);	
	$form['general']['quote_main_phone'] = array(
		'#title' => t('Phone'),
		'#type'  => 'textfield',
		'#default_value' => variable_get('quote_main_phone'),
	);
	$form['general']['quote_form_title'] = array(
		'#title' => t('Main form title'),
		'#type'  => 'textfield',
		'#default_value' => variable_get('quote_form_title'),
	);	
	$form['general']['quote_form_text'] = array(
		'#title' => t('Main form text'),
		'#type'  => 'textarea',
		'#default_value' => variable_get('quote_form_text'),
	);	
	return system_settings_form($form);
}