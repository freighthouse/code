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
?>
<?php
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

    // If this is the body, store the value
    if ($field->class == 'field-issue-summary') {
      $body = $field->content;
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
      foreach ($field->handler->view->result[$current_row]->_field_data['nid']['entity']->field_taxonomy_region['und'] as $delta => $item) {

        // If this is tid 1, we output US markup
        if ($item['tid'] == '1') {
          $field_taxonomy_region .= '<div class="issue-region-icon-us">USA</div>';
        }

        // If this is tid 6, we output global markup
        if ($item['tid'] == '6') {
          $field_taxonomy_region .= '<div class="issue-region-icon-global">Global</div>';
        }

      }

    }

    // If this is the take action section, store the markup
    if ($field->class == 'field-take-action-group') {
      $take_action = $field->content;
      if ($take_action == '') {
        $take_action_class = 'no-take-action ';
      }
      else {
        $take_action_class = 'has-take-action ';
      }
    }

  }

?>

<div class="featured-issue-wrapper <?php print $take_action_class; ?>row-<?php print $current_row; ?>">
  <a class="featured-issue-link" href="<?php print $path; ?>">
    <div class="featured-issue-title"><?php print $title; ?></div>
    <div class="featured-issue-description"><?php print $body; ?></div>
  </a>
  <div class="featured-issue-region">
    <?php if(isset($field_taxonomy_region)): print $field_taxonomy_region; endif; ?>
  </div>
</div>
<div class="featured-issue-take-action">
  <?php print $take_action; ?>
</div>