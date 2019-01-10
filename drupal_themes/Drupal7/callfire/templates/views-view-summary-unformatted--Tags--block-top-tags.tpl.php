<?php
/**
 * @file views-view-summary-unformatted.tpl.php
 * Default simple view template to display a group of summary lines
 *
 * This wraps items in a span if set to inline, or a div if not.
 *
 * @ingroup views_templates
 */
?>
<div class="item-list">
	<ul class="views-summary">
	<?php foreach ($rows as $id => $row): ?>
	  <?php print (!empty($options['inline']) ? '<span' : '<li') . '>'; ?>
	    <?php if (!empty($row->separator)) { print $row->separator; } ?>
	    <a href="<?php print strtolower($row->url); ?>"<?php print !empty($row_classes[$id]) ? ' class="' . $row_classes[$id] . '"' : ''; ?>><?php print $row->link; ?></a>
	    <?php if (!empty($options['count'])): ?>
	      (<?php print $row->count; ?>)
	    <?php endif; ?>
	  <?php print !empty($options['inline']) ? '</span>' : '</li>'; ?>
	<?php endforeach; ?>
	</ul>
</div>