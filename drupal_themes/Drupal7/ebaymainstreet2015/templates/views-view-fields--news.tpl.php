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

    // If this is the path, store the value
    if ($field->class == 'path') {
      $path = $field->content;
    }

    // If this is the date, store the value
    if ($field->class == 'created') {
      $created = $field->content;
    }

    // If this is the photo, store the value
    if ($field->class == 'field-news-photo') {
      $photo = $field->content;
    }

    // If this is the title, store the value
    if ($field->class == 'title') {
      $title = $field->content;
    }

    // If this is the body, store the value
    if ($field->class == 'field-news-summary') {
      $body = $field->content;
    }

    // If this is the region, loop over the values and create the output
    if ($field->class == 'term-node-tid') {

      // Initialize the output variable
      $field_taxonomy_region = '';

      if (isset($field->handler->view->result[$current_row]->_field_data['nid']['entity']->field_taxonomy_region['und'])) {
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
        } // end foreach
      } // end if
    } // end if

  }
?>


<div class="front-page-news-wrapper row-<?php print $current_row; ?>">
    <div class="front-page-news-photo"><?php if(isset($photo)): ?><?php print $photo; ?><?php endif; ?></div>

        <div class="front-page-news-text<?php if(!isset($photo) || $photo == ''): ?> no-photo<?php endif; ?>">
            <a class="front-page-news-link" href="<?php print $path; ?>">
                <div class="front-page-news-date"><?php if(isset($created)): ?><?php print $created; ?><?php endif; ?></div>
                <div class="front-page-news-title"><?php if(isset($title)): ?><?php print $title; ?><?php endif; ?></div>
                <div class="front-page-news-description"><?php if(isset($body)): ?><?php print $body; ?><?php endif; ?></div>
            </a>
        </div>
    <!--    <div class="policy-paper-block-read-article"></div>-->
<!--    <div class="front-page-news-regions">-->
<!--        --><?php //if(isset($field_taxonomy_region)): print $field_taxonomy_region; endif; ?>
<!--    </div>-->
</div>