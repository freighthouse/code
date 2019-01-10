<?php

	/**
	 * @file
	 * This template handles the layout of the views exposed filter form.
	 *
	 * Variables available:
	 * - $widgets: An array of exposed form widgets. Each widget contains:
	 * - $widget->label: The visible label to print. May be optional.
	 * - $widget->operator: The operator for the widget. May be optional.
	 * - $widget->widget: The widget itself.
	 * - $sort_by: The select box to sort the view using an exposed form.
	 * - $sort_order: The select box with the ASC, DESC options to define order. May be optional.
	 * - $items_per_page: The select box with the available items per page. May be optional.
	 * - $offset: A textfield to define the offset of the view. May be optional.
	 * - $reset_button: A button to reset the exposed filter applied. May be optional.
	 * - $button: The submit button for the form.
	 *
	 * @ingroup views_templates
	 */
?>
<?php
	if (!empty($q)):
	// This ensures that, if clean URLs are off, the 'q' is added first so that
	// it shows up first in the URL.
		print $q;
	endif;
	$search_counts = variable_get('search_counts', ['rif_test' => 13495, 'site_search' => '375']);
?>
<div class="views-exposed-form outer-container">
	<div class="views-exposed-form container">
<!--		<div class="col-md-6">-->
		<div class="col-md-12">
			<div class="search-bar row ">
				<div class="input-group">
					<?php foreach ($widgets as $id => $widget): ?>
						<?php print $widget->widget; ?>
					<?php endforeach; ?>
					<?php print $button; ?>
				</div>
			</div>
		</div>
<!--		<div class="col-md-6">-->
<!--			<div class="large-search-buttons">-->
<!--				<a href="/literacy-central/search" class="active"><h3>Books &amp; Activities</h3><p>--><?php //print $search_counts['rif_test'] ?><!-- results</p></a>-->
<!--				<a href="/search"><h3>Resources</h3><p>--><?php //print $search_counts['site_search'] ?><!-- results</p></a>-->
<!--			</div>-->
<!--		</div>-->
	</div>
</div>
