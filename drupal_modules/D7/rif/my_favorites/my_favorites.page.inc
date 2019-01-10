<?php

	function shared_favorites_page($node) {
		$content = array(
			'#type' => 'markup',
			'#markup' => _get_shared_markup($node)
		);

		return $content;
	}

	function _get_shared_markup($node) {
		$markup_to_return = '';
		//dsm($node);
		$emw_node = entity_metadata_wrapper('node', $node);
		$folder_is_shareable = $emw_node->field_shared->value();

		$back_nav_block = module_invoke('content_bundles', 'block_view', 'rif_back_nav');
		$header_markup = render($back_nav_block['content']);
		//$favorites_header_block = module_invoke('my_favorites', 'block_view', 'my_favorites_header');
		$header_markup .= '
			<div class="header-block my-favorites">
				<div class="container">
					<h1>'.$node->title.'</h1>
				</div>
			</div>';

		if($folder_is_shareable) {
			$renderable_folder_full = node_view($node, $view_mode = 'full', $langcode = NULL);
			$favorite_markup = render($renderable_folder_full);
		} else {
			$favorite_markup = '
				<div class="panel panel-default panel-favorites-list">
					<div class="panel-body">The favorites folder requested is either private or could not be found.</div>
				</div>;';
		}

		$favorite_markup = '<div class="brand-container"><div class="container">'.$favorite_markup.'</div></div>';

		$markup_to_return .= $header_markup;
		$markup_to_return .= $favorite_markup;

		//'<p>'.t('The shared favorites page to view is: '.$node->title).'.</p>'
		return $markup_to_return;
	}