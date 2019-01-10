<?php

	/**
	 * @file
	 * Default theme implementation to display a node.
	 *
	 * Available variables:
	 * - $title: the (sanitized) title of the node.
	 * - $content: An array of node items. Use render($content) to print them all,
	 *   or print a subset such as render($content['field_example']). Use
	 *   hide($content['field_example']) to temporarily suppress the printing of a
	 *   given element.
	 * - $user_picture: The node author's picture from user-picture.tpl.php.
	 * - $date: Formatted creation date. Preprocess functions can reformat it by
	 *   calling format_date() with the desired parameters on the $created variable.
	 * - $name: Themed username of node author output from theme_username().
	 * - $node_url: Direct URL of the current node.
	 * - $display_submitted: Whether submission information should be displayed.
	 * - $submitted: Submission information created from $name and $date during
	 *   template_preprocess_node().
	 * - $classes: String of classes that can be used to style contextually through
	 *   CSS. It can be manipulated through the variable $classes_array from
	 *   preprocess functions. The default values can be one or more of the
	 *   following:
	 *   - node: The current template type; for example, "theming hook".
	 *   - node-[type]: The current node type. For example, if the node is a
	 *     "Blog entry" it would result in "node-blog". Note that the machine
	 *     name will often be in a short form of the human readable label.
	 *   - node-teaser: Nodes in teaser form.
	 *   - node-preview: Nodes in preview mode.
	 *   The following are controlled through the node publishing options.
	 *   - node-promoted: Nodes promoted to the front page.
	 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
	 *     listings.
	 *   - node-unpublished: Unpublished nodes visible only to administrators.
	 * - $title_prefix (array): An array containing additional output populated by
	 *   modules, intended to be displayed in front of the main title tag that
	 *   appears in the template.
	 * - $title_suffix (array): An array containing additional output populated by
	 *   modules, intended to be displayed after the main title tag that appears in
	 *   the template.
	 *
	 * Other variables:
	 * - $node: Full node object. Contains data that may not be safe.
	 * - $type: Node type; for example, story, page, blog, etc.
	 * - $comment_count: Number of comments attached to the node.
	 * - $uid: User ID of the node author.
	 * - $created: Time the node was published formatted in Unix timestamp.
	 * - $classes_array: Array of html class attribute values. It is flattened
	 *   into a string within the variable $classes.
	 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
	 *   teaser listings.
	 * - $id: Position of the node. Increments each time it's output.
	 *
	 * Node status variables:
	 * - $view_mode: View mode; for example, "full", "teaser".
	 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
	 * - $page: Flag for the full page state.
	 * - $promote: Flag for front page promotion state.
	 * - $sticky: Flags for sticky post setting.
	 * - $status: Flag for published status.
	 * - $comment: State of comment settings for the node.
	 * - $readmore: Flags true if the teaser content of the node cannot hold the
	 *   main body content.
	 * - $is_front: Flags true when presented in the front page.
	 * - $logged_in: Flags true when the current user is a logged-in member.
	 * - $is_admin: Flags true when the current user is an administrator.
	 *
	 * Field variables: for each field instance attached to the node a corresponding
	 * variable is defined; for example, $node->body becomes $body. When needing to
	 * access a field's raw values, developers/themers are strongly encouraged to
	 * use these variables. Otherwise they will have to explicitly specify the
	 * desired field language; for example, $node->body['en'], thus overriding any
	 * language negotiation rule that was previously applied.
	 *
	 * @see template_preprocess()
	 * @see template_preprocess_node()
	 * @see template_process()
	 *
	 * @ingroup themeable
	 */

	if(!empty($filters)){
		$showFilters = true;

		$full_array = array();
		$display_array = array();

		if(in_array('type', $filters)) {
			$filters_to_show = array();
			$temp_filter = new stdClass();
			$temp_filter->name = "Resources";
			$temp_filter->data_link = "type";
			$temp_filter->sort_override = null;
			$filters_to_show[] = $temp_filter;
		}

		if(in_array('grades', $filters)) {
			$temp_filter = new stdClass();
			$temp_filter->name = "Grades";
			$temp_filter->data_link = "grades";

			$name = 'grade_levels';
			$myvoc = taxonomy_vocabulary_machine_name_load($name);
			$tree = taxonomy_get_tree($myvoc->vid);
			$temp_filter->sort_override = null;
			foreach ($tree as $term) {
				$temp_filter->sort_override[] = $term->name;
			}

			$filters_to_show[] = $temp_filter;
		}

		if(in_array('themes', $filters)) {
			$temp_filter = new stdClass();
			$temp_filter->name = "Themes";
			$temp_filter->data_link = "themes";
			$temp_filter->sort_override = null;
			$filters_to_show[] = $temp_filter;
		}

		if(in_array('lexile', $filters)) {
			$temp_filter = new stdClass();
			$temp_filter->name = "Lexile Range";
			$temp_filter->data_link = "lexile";
			$name = 'lexile_range';
			$myvoc = taxonomy_vocabulary_machine_name_load($name);
			$tree = taxonomy_get_tree($myvoc->vid);
			$temp_filter->sort_override = null;
			foreach ($tree as $term) {
				$temp_filter->sort_override[] = $term->name;
			}
			$filters_to_show[] = $temp_filter;
		}

		foreach($collection_books_id as $id => $item) {
			$temp_object = new stdClass();

			$emw_node = entity_metadata_wrapper('node', $item->nid);

			$temp_object->nid = $emw_node->getIdentifier();
			$temp_object->title = $emw_node->title->value();

			$bundle_data = entity_get_info('node');
			$temp_object->type[] = $bundle_data['bundles'][$emw_node->getBundle()]['label'];

			// Set Grade for this item
			$temp_object->grades = null;
			if(!empty($emw_node->supported_grades)) {
				$tempgrades = $emw_node->supported_grades->value();
				if(!empty($tempgrades)) {
					foreach($tempgrades as $gradeItem) {
						$temp_object->grades[] = $gradeItem->name;
					}
				}
			}

			// Set Lexile for this item
			$temp_object->lexile = null;
			if(!empty($emw_node->lexile_range)) {
				$temp_lexile = $emw_node->lexile_range->value();
				if(!empty($temp_lexile)){
					$temp_object->lexile[] = $emw_node->lexile_range->value()->name;
				}
			}

			// Set Theme for this item
			$temp_object->themes = null;
			if(!empty($emw_node->field_themes)) {
				$tempthemes = $emw_node->field_themes->value();
				if(!empty($tempthemes)) {
					foreach($tempthemes as $themeItem) {
						$temp_object->themes[] = $themeItem->name;
					}
				}
			}

			$renderableNode = node_view($item, 'search_results');
			$temp_object->full_html = drupal_render($renderableNode);

			$full_array[$id] = $temp_object;
		}
?>

<script>

	var full_array = <?php echo json_encode($full_array); ?>;
	var facet_types = <?php echo json_encode($filters_to_show); ?>

	//var display_array = full_array.filter( gradeFilterFunction );
	//console.log(display_array);
	jQuery(document).ready(function () {
		//var facet_types = [{name: 'Type Filter', data_link: 'type'}, {name: 'Grade Filter', data_link:'grades'}, { name: 'Theme Filter', data_link:'themes'}, { name: 'Lexile Filter', data_link: 'lexile'}];

		var myCFC = new CustomFacetController({
			results_div: 	'.collection-filter-results',
			facet_div: 		'.search-facets',
			data_array: 	full_array,
			facet_types: 	facet_types
		});

//		updateCustomSearchDisplay(display_array, '.collection-filter-results');
	});
</script>

<?php } else {
		$showFilters = false;
	}?>


<div class="rif-back-nav shortened" style="background-color: <?php print $background_color; ?>"></div>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
	<?php print render($title_prefix); ?>
	<?php print render($title_suffix); ?>

	<div class="collection-header-image-container" style="background-color: <?php print $background_color; ?>">
		<div class="container">
			<div class="row">
				<div class="col-xs-12 col-sm-12 col-md-7 col-lg-5 collection-banner-text">
					<h2><?php print $banner_text ?></h2>
				</div>
			</div>
		</div>
		<div class="collection-header-image-inner-container">
			<div class="collection-header-image" style="background-image: url(<?php print $background_img_src; ?>);"></div>
		</div>
	</div>
	<?php if($from_search != '') : ?>
		<div class="back-to-book-button">
			<div class="button-container tabs header-overlay">
				<div class="container">
					<a href="<?php print $referer_path; ?>" type="button" class="btn active">
						<i class="fa fa-long-arrow-left pull-left"></i>
						<span>Back to Search</span>
					</a>
				</div>
			</div>
		</div>
	<?php endif; ?>
	<div class="container view-search">
		<?php if($tabs): ?>
			<div id="tabs">
				<ul class="tabs primary">
					<?php print render($tabs); ?>
				</ul>
			</div>
		<?php endif; ?>
		<div class="row">
			<div class="col-xs-12 collection-content">
				<h2><?php print $display_title; ?></h2>
				<?php print render($content['body']); ?>
			</div>
		</div>
		<div class="row collection-content-row">
		<?php if( $showFilters ) { ?>
		<div class="col-xs-12 col-md-3">
			<div class="search-facets">
				<h3>Filter</h3>
			</div>
			<div class="sponsors-wrapper">
				<?php 
					$block = block_load('views', 'sponsors-block');
					$output = drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
					print $output;
				?>	
			</div>
		</div>
		<div class="col-xs-12 col-md-9">
			<div class="row collection-content collection-filter-results">
		<?php } else { ?>
		<div class="no-filters-container">
			<div class="collection-content collection-filter-results">
		<?php } ?>
			<?php
				$outerRows = [];
				$counter = 0;
				$fullRows = -1;
				foreach ($collection_books_id as $id => $row):
					$relativeID = $counter % 4;
					if ($relativeID == 0) {
						$fullRows++;
					}
					$outerRows[$fullRows][floor($relativeID / 2)][$id] = $row;
					$counter++;
				endforeach;
			?>
			<div class="col-md-12">
				<?php foreach ($outerRows as $fullRow) : ?>
					<div class="row">
						<?php foreach ($fullRow as $innerRow) : ?>
							<div class="col-md-6">
								<div class="row">
									<?php foreach ($innerRow as $id => $element) : ?>
										<div class="col-xs-12 col-sm-6">
											<div class="">
												<?php $renderableNode = node_view($element, 'search_results'); ?>
												<?php print drupal_render($renderableNode); ?>
											</div>
										</div>
									<?php endforeach; ?>
								</div>
							</div>
						<?php endforeach; ?>
					</div>
				<?php endforeach; ?>
			</div>
		</div>
		</div>
		</div>
		<?php //print render($content['field_collection_books']); ?>
	</div>

</div>
