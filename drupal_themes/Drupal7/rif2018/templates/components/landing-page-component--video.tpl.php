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
<div class="<?php print $classes; ?> container-fluid clearfix"<?php print $attributes; ?>>
  <div class="row">
    <div class="component__video__image col-md-6 <?php if ($video_pos == 'right') { print 'col-md-push-6'; } ?>">
      <?php if ($content['field_video_thumbnail']): ?>
        <?php print render($content['field_video_thumbnail']); ?>
        <?php if ($video_button_text): ?>
          <a
            id="<?php print $modal_trigger_target; ?>"
            data-toggle="modal"
            data-target="#modal-<?php print $modal_trigger_target; ?>"
            class="media-element file-wysiwyg btn btn-white"
          >
            <?php print $video_button_text; ?>
          </a>
        <?php endif; ?>
      <?php endif; ?>
    </div>

    <div class="component__video__content col-md-6 <?php if ($video_pos == 'right') { print 'col-md-pull-6'; } ?>">
      <h2<?php print $title_attributes; ?>>
        <?php print $title; ?>
      </h2>

      <?php hide($content['field_video_embed_code']); ?>
      <?php hide($content['field_video_modal_reference']); ?>
      <?php print render($content); ?>
    </div>
  </div>

  <?php print render($content['field_video_modal_reference']); ?>
</div>
