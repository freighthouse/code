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
  <div class="homepage-hero-wrapper">

    <div class="homepage-hero-image">
      <?php if (count($content['field_hero_image']['#items']) > 1): ?>
      <div class="homepage-hero-slider">
        <?php print render($content['field_hero_image']); ?>
      </div>
      <?php else: ?>
      <?php print render($content['field_hero_image']); ?>
      <?php endif; ?>
    </div>

    <div class="homepage-hero-text-wrapper">
      <div class="homepage-hero-content">

        <div class="homepage-hero-text-block">

          <div class="homepage-hero-title">
            <?php print render($content['field_hero_heading']); ?>
          </div>

          <div class="homepage-hero-description">
            <?php print render($content['field_hero_description']); ?>
          </div>

        </div>

      </div>
    </div>

  </div>
</div>