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
  // $styleAttr = '';
  // if(!empty($fields['uri']->raw)){
  //   $imageUri = $fields['uri']->raw;
  //   $imageUrl = image_style_url('featured_member_background', $imageUri);
  //   $styleAttr = ' style="background-image:url(' . $imageUrl . ')"';
  // }
?>

<div class="all-fields-wrapper">
  <?php if (!empty($fields['field_member_photo']->separator)): ?>
  <?php print $fields['field_member_photo']->separator; ?>
  <?php endif; ?>

  <?php print $fields['field_member_photo']->wrapper_prefix; ?>
  <?php print $fields['field_member_photo']->label_html; ?>
  <?php print $fields['field_member_photo']->content; ?>
  <?php print $fields['field_member_photo']->wrapper_suffix; ?>
  <div class="text-fields">
    <div class="content">
      <?php foreach ($fields as $id => $field): ?>
        <?php if($id != 'field_member_photo'): ?>
          <?php if (!empty($field->separator)): ?>
            <?php print $field->separator; ?>
          <?php endif; ?>

          <?php print $field->wrapper_prefix; ?>
            <?php print $field->label_html; ?>
            <?php print $field->content; ?>
          <?php print $field->wrapper_suffix; ?>
        <?php endif; ?>
      <?php endforeach; ?>
    </div>
  </div>
</div>

<!-- <div class="featured-member-wrapper">
<a class="featured-member-link" href="[path]">
<div class="featured-member-photo">[field_member_photo]</div>
<div class="featured-member-title">[title]</div>
<div class="featured-member-business">[field_member_business_name]</div>
<div class="featured-member-location">[field_member_business_location]</div>
</a>
</div>
<div class="featured-member-view-more"><a href="/featured-members">View Featured Members</a></div> -->