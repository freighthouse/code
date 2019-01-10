<?php

/**
 * @file
 * Default theme implementation for entities.
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
 *
 * Wrapper markup exists at the Paragraph level.
 */
?>

<?php if(isset($content['field_feature_image'])): ?>
 <div class="feature__image<?php if(isset($content['field_feature_title_logo'])): ?> feature__image__logo<?php endif; ?>">
    <?php print render($content['field_feature_image']); ?>
  </div>
<?php endif; ?>
<div class="feature__content">
  <h2 class="feature__title">
    <?php if(isset($content['field_feature_title_logo'])): ?>
      <?php print render($content['field_feature_title_logo']); ?>
    <?php else: ?>
      <?php print $title; ?>
    <?php endif; ?>
  </h2>

  <?php print render($content); ?>
</div>