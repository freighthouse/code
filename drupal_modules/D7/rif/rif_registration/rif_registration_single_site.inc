<?php
	function single_site_profile_edit($node) {

		/* ****************************************
		 * 		Setup the left Region
		 * **************************************** */
		module_load_include('inc', 'node', 'node.pages');
		$type_name = node_type_get_name($node);
		drupal_set_title(t('<em>Edit @type</em> @title', array('@type' => $type_name, '@title' => $node->title)), PASS_THROUGH);
		$leftRegion = drupal_get_form($node->type . '_node_form', $node);
		$leftRegion = render($leftRegion);

		/* ****************************************
		 * 		Setup the right Region
		 * **************************************** */
		$rightRegion = module_invoke('rif_registration', 'block_view', 'profile_status_single_site');
		$rightRegion = render($rightRegion['content']);

//		$toReturn = '
//			<div class="container panel-push-down form-horizontal">
//				<div class="col-md-8">
//					'.$leftRegion.'
//				</div>
//				<div class="col-md-4">
//					'.$rightRegion.'
//				</div>
//			</div>
//		';

		$toReturn = '
		<div class="panel-push-down form-horizontal">
			'.$leftRegion.'
		</div>
		';

		/* ****************************************
		 * 		Add Jumbotron header
		 * **************************************** */
		$jumbotron_view = '';
		$jumbotron_view = node_view(node_load(3515), 'full');
		$back_nav_block = module_invoke('content_bundles', 'block_view', 'rif_panel_separator');
		$header_markup = render($back_nav_block['content']);
		$toReturn = $header_markup.$toReturn;
		$toReturn = drupal_render($jumbotron_view).$toReturn;


		/* ****************************************
		 * 		Create Renderable content array and send
		 * **************************************** */
		$content['raw_markup'] = array(
			'#type' => 'markup',
			'#markup' => $toReturn,
		);
		return $content;
	}