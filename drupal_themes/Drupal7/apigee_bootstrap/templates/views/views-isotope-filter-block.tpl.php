<?php
/**
 * @file views-isotope-filter-block.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<div id="isotope-options">


  <select id="filters" class="option-set clearfix" data-option-key="filter">
    <option value="*" data-option-value="*" data-option-key="filter" class="selected"><?php print t('All'); ?></option>
    <?php foreach ( $rows as $id => $row ): ?>
        <?php
        // remove characters that cause problems with classes
        // this is also do to the isotope elements
        $dataoption = trim(strip_tags(strtolower($row)));
        $dataoption = str_replace(' ', '-', $dataoption);
        $dataoption = str_replace('/', '-', $dataoption);
        $dataoption = str_replace('&amp;', '', $dataoption);
        ?>
      <option class="filterbutton" value=".<?php print $dataoption; ?>" data-option-key="filter" data-option-value=".<?php print $dataoption; ?>"><?php print trim($row); ?></option>
    <?php endforeach; ?>
  </select>
</div>

