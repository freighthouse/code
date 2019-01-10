<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */

  // Loop over the fields
  foreach ($fields as $id => $field) {

    // Get the current row number
    if (isset($field->handler->view->row_index)) {
      $current_row = $field->handler->view->row_index;
    }

    // If this is the title, store the value
    if ($field->class == 'title') {
      $title = $field->content;
    }

    // If this is the path, store the value
    if ($field->class == 'path') {
      $path = $field->content;
    }

    // If this is the region, loop over the values and create the output
    if ($field->class == 'field-taxonomy-region') {
      // Initialize the output variable
      $field_taxonomy_region = '';
      // Loop over the values
      $num_icons = 0;
      foreach ($field->handler->view->result[$current_row]->_field_data['nid']['entity']->field_taxonomy_region['und'] as $delta => $item) {

        // If this is tid 1, we output US markup
        if ($item['tid'] == '1') {
          $field_taxonomy_region .= '<div class="issue-region-icon-us">USA</div>';
          $num_icons++;
        }

        // If this is tid 2, we output asia markup
        if ($item['tid'] == '2') {
          $field_taxonomy_region .= '<div class="issue-region-icon-asia">Asia</div>';
          $num_icons++;
        }

        // If this is tid 3, we output europe markup
        if ($item['tid'] == '3') {
          $field_taxonomy_region .= '<div class="issue-region-icon-europe">Europe</div>';
          $num_icons++;
        }

        // If this is tid 4, we output australia markup
        if ($item['tid'] == '4') {
          $field_taxonomy_region .= '<div class="issue-region-icon-australia">Australia</div>';
          $num_icons++;
        }

        // If this is tid 6, we output global markup
        if ($item['tid'] == '6') {
          $field_taxonomy_region .= '<div class="issue-region-icon-global">Global</div>';
          $num_icons++;
        }

        // If this is tid 7, we output northamerica markup
        if ($item['tid'] == '7') {
          $field_taxonomy_region .= '<div class="issue-region-icon-northamerica">North America</div>';
          $num_icons++;
        }

        // If this is tid 8, we output southamerica markup
        if ($item['tid'] == '8') {
          $field_taxonomy_region .= '<div class="issue-region-icon-southamerica">South America</div>';
          $num_icons++;
        }

        // If this is tid 9, we output africa markup
        if ($item['tid'] == '9') {
          $field_taxonomy_region .= '<div class="issue-region-icon-africa">Africa</div>';
          $num_icons++;
        }

        if ($num_icons >= 3) {
          $expand_class = ' expand';
        }
        else {
          $expand_class = '';
        }

      }
    }

  }
?>

<div class="issues-listing-wrapper row-<?php print $current_row; ?>">
  <a class="issues-listing-link" href="<?php print $path; ?>">
    <div class="issues-listing-title"><?php print $title; ?></div>
    <div class="issues-listing-bottom">
      <div class="issues-listing-read-more"><span class="visuallyhidden">Read article</span></div>
    </div>
    <div class="issues-listing-region">
      <?php if(isset($field_taxonomy_region)): print $field_taxonomy_region; endif; ?>
    </div>
  </a>
</div>