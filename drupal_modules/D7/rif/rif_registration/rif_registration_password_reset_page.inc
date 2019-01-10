<?php

	function get_password_reset() {
		$toReturn = "";
		module_load_include('pages.inc', 'user', 'user');
		$form = drupal_get_form('user_pass');

		$jumbo_node_html = node_view(node_load(5087));

		$panel_separator = module_invoke('content_bundles', 'block_view', 'rif_panel_separator');
		$panel_markup = render($panel_separator['content']);

		$toReturn = '<div class="header">' . render($jumbo_node_html) . '</div>' . $panel_markup . '
<div class="container panel-push-down">' . drupal_render($form) . '</div>';

		$content['raw_markup'] = array(
			'#type' => 'markup',
			'#markup' => $toReturn,
		);
		return $content;
	}