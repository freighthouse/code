<?php

	function default_campaign_form($form, &$form_state) {

		$query = new EntityFieldQuery();
		$related_multi_sites = $query
			->entityCondition('entity_type', 'node')
			->propertyCondition('type', 'content_campaign_lc')
			->propertyCondition('status',1);

		$result = $query->execute();
		$lc_campaign_nids = array_keys($result['node']);
		$lc_campaign_options = array();
		foreach($lc_campaign_nids as $id => $campaign_nid) {
			$emw_campaign = entity_metadata_wrapper('node', $campaign_nid);
			$lc_campaign_options[$campaign_nid] = t($emw_campaign->label());
		}

		$form['content_bundles_default_campaign'] = array(
			'#type' => 'radios',
			'#title' => t('Default Literacy Central Content Campaign'),
			'#options' => $lc_campaign_options,
			'#default_value' => variable_get('content_bundles_default_campaign'),
			'#description' => t('Set the default content campaign'),
		);


		$query = new EntityFieldQuery();
		$related_multi_sites = $query
			->entityCondition('entity_type', 'node')
			->propertyCondition('type', 'content_campaign_rif')
			->propertyCondition('status',1);

		$result = $query->execute();
		$rif_campaign_nids = array_keys($result['node']);
		$rif_campaign_options = array();
		foreach($rif_campaign_nids as $id => $campaign_nid) {
			$emw_campaign = entity_metadata_wrapper('node', $campaign_nid);
			$rif_campaign_options[$campaign_nid] = t($emw_campaign->label());
		}
		$form['content_bundles_rif_default_campaign'] = array(
			'#type' => 'radios',
			'#title' => t('Default RIF.org Content Campaign'),
			'#options' => $rif_campaign_options,
			'#default_value' => variable_get('content_bundles_rif_default_campaign'),
			'#description' => t('Set the default content campaign for RIF.org'),
		);


		$query = new EntityFieldQuery();
		$related_multi_sites = $query
			->entityCondition('entity_type', 'node')
			->propertyCondition('type', 'content_campaign_ln')
			->propertyCondition('status',1);

		$result = $query->execute();
		$ln_campaign_nids = array_keys($result['node']);
		$ln_campaign_options = array();
		foreach($ln_campaign_nids as $id => $campaign_nid) {
			$emw_campaign = entity_metadata_wrapper('node', $campaign_nid);
			$ln_campaign_options[$campaign_nid] = t($emw_campaign->label());
		}
		$form['content_bundles_ln_default_campaign'] = array(
			'#type' => 'radios',
			'#title' => t('Default Literacy Network Content Campaign'),
			'#options' => $ln_campaign_options,
			'#default_value' => variable_get('content_bundles_ln_default_campaign'),
			'#description' => t('Set the default content campaign for Literacy Network'),
		);

		return(system_settings_form($form));
	}

	function config_pop_up_modal_form($form, &$form_state) {
		$form['content_bundles_popup_modal_toggle'] = array(
			'#type' => 'checkbox',
			'#title' => t('Enable auto popup'),
			'#default_value' => variable_get('content_bundles_popup_modal_toggle'),
		);
		$form['where_to_show_container'] =  array(
			'#type' => 'fieldset',
			'#title' => t('Auto Popup Locations:'),
			'#collapsible' => TRUE,
		);

		$form['where_to_show_container']['content_bundles_popup_modal_show_on_rif_home'] = array(
			'#type' => 'checkbox',
			'#title' => t('RIF.org Home'),
			'#default_value' => variable_get('content_bundles_popup_modal_show_on_rif_home'),
		);
		$form['where_to_show_container']['content_bundles_popup_modal_show_on_literacy_network_home'] = array(
			'#type' => 'checkbox',
			'#title' => t('Literacy Network Home'),
			'#default_value' => variable_get('content_bundles_popup_modal_show_on_literacy_network_home'),
		);
		$form['where_to_show_container']['content_bundles_popup_modal_show_on_literacy_central_home'] = array(
			'#type' => 'checkbox',
			'#title' => t('Literacy Central Home'),
			'#default_value' => variable_get('content_bundles_popup_modal_show_on_literacy_central_home'),
		);

		$temp_var = variable_get('content_bundles_popup_modal_body_text');
		if(empty($temp_var)) {
			$temp_var = array('format'=> NULL, 'value' => '');
		}
		$form['content_bundles_popup_modal_body_text'] = array(
			'#type' => 'text_format',
			'#base_type' => 'textarea',
			'#title' => t('Modal Body'),
			'#rows' => '15',
			'#format' => $temp_var['format'],
			'#default_value' => $temp_var['value'],
		);

		$temp_var = variable_get('content_bundles_popup_modal_footer_text');
		if(empty($temp_var)) {
			$temp_var = array('format'=> NULL, 'value' => '');
		}
		$form['content_bundles_popup_modal_footer_text'] = array(
			'#type' => 'text_format',
			'#base_type' => 'textarea',
			'#title' => t('Modal Footer'),
			'#rows' => '8',
			'#format' => $temp_var['format'],
			'#default_value' => $temp_var['value'],
		);

		return(system_settings_form($form));
	}