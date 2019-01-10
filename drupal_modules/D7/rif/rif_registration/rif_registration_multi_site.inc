<?php
	function multi_site_profile_edit($node) {
		module_load_include('inc', 'node', 'node.pages');
		$type_name = node_type_get_name($node);
		drupal_set_title(t('<em>Edit @type</em> @title', array('@type' => $type_name, '@title' => $node->title)), PASS_THROUGH);
		$toReturn = drupal_get_form($node->type . '_node_form', $node);
		$toReturn = render($toReturn);
		$toReturn = '<div class="container form-horizontal">'.$toReturn.'</div>';

		$content['raw_markup'] = array(
			'#type' => 'markup',
			'#markup' => $toReturn,
		);
		return $content;
	}