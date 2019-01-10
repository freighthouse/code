<?php
/**
 * @file
 * Default theme implementation for beans.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) entity label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-{ENTITY_TYPE}
 *   - {ENTITY_TYPE}-{BUNDLE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<div class="<?php print $classes; ?> clearfix hidden"<?php print $attributes; ?>>
  <?php if ($content['field_announcement_text']['#object']->field_announcement_activate['und'][0]['value'] == 1): ?>
  <div class="announcement-wrapper seen">
  <?php else: ?>
  <div class="announcement-wrapper hidden seen">
  <?php endif; ?>

    <div class="announcement-content">

      <div class="announcement-text">
        <?php print render($content['field_announcement_text']); ?>
      </div>

      <div class="announcement-close-wrapper">
        <a class="announcement-close" href="#">
          <span class="visuallyhidden">Close</span>
        </a>
      </div>

    </div>

  </div>
</div>