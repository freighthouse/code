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
 */
?>

<div class="<?php print $classes; ?> feature-large--layout-<?php print $img_pos; ?> container-fluid" <?php print $attributes; ?>>
  <div class="row">
    <div class="col-md-6 <?php if ($img_pos == 'right') { print 'col-md-push-6'; } ?> large-feature__image">
      <?php print render($content['field_feature_background_image']); ?>

      <?php if (isset($bg_color)): ?>
        <div
          class="large-feature-gradient large-feature-gradient--bottom"
          style="background-image: linear-gradient(to bottom, transparent, <?php print $bg_color; ?> 80%);"
        ></div>

        <?php if ($img_pos == 'left'): ?>
          <div
            class="large-feature-gradient large-feature-gradient--edge"
            style="background-image: linear-gradient(to right, transparent, <?php print $bg_color; ?> 80%);"
          ></div>
        <?php else: ?>
          <div
            class="large-feature-gradient large-feature-gradient--edge"
            style="background-image: linear-gradient(to left, transparent, <?php print $bg_color; ?> 80%);"
          ></div>
        <?php endif; ?>
      <?php endif; ?>
    </div>

    <div class="col-md-6 <?php if ($img_pos == 'right') { print 'col-md-pull-6'; } ?> large-feature__content">
      <h2 class="feature-large__title"><?php print $title; ?></h2>
      <?php print render($content); ?>
    </div>
  </div>
</div>
