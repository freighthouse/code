<?php
	function get_sign_in_page_ln()
	{
		$toReturn = "";

//$form = drupal_get_form('rif_registration_ln_register_form');

		if(!user_is_anonymous()){
			drupal_goto('literacy-network/my-account');
		}
		$form = drupal_get_form('user_login_block');

		$jumbo_node_html = node_view(node_load(5085));

		$back_nav_block = module_invoke('content_bundles', 'block_view', 'rif_panel_separator');
		$header_markup = render($back_nav_block['content']);

		$toReturn = '<div class="header">' . render($jumbo_node_html) . '</div>' . $header_markup . '
<div class="container panel-push-down">' . drupal_render($form) . '</div>
';

		$content['raw_markup'] = array(
			'#type' => 'markup',
			'#markup' => $toReturn,
		);

		return $content;
	}

	function get_sign_in_page_lc()
	{
		$toReturn = "";

//$form = drupal_get_form('rif_registration_ln_register_form');

		if(!user_is_anonymous()){
			drupal_goto('literacy-central/my-account');
		}

		$form = drupal_get_form('user_login_block');

		$jumbo_node_html = node_view(node_load(5085));

		$back_nav_block = module_invoke('content_bundles', 'block_view', 'rif_back_nav');
		$header_markup = render($back_nav_block['content']);
		$panel_separator = module_invoke('content_bundles', 'block_view', 'rif_panel_separator');
		$panel_markup = render($panel_separator['content']);

		$toReturn = $header_markup.'<div class="header">' . render($jumbo_node_html) . '</div>' . $panel_markup . '
<div class="container panel-push-down">' . drupal_render($form) . '</div>
';

		$content['raw_markup'] = array(
			'#type' => 'markup',
			'#markup' => $toReturn,
		);

		return $content;
	}
