<?php

	function get_registration_page_lc() {
		$toReturn = "";

		$form = drupal_get_form('user_register_form');

		$jumbo_node_html = node_view(node_load(5095));

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
