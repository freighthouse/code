<?php
/**
 * @file
 * Jcerda @FreighthouseNYC
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
<div class="<?php print $classes; ?> clearfix" <?php print $attributes; ?>>
  <div class="dh_image">
    <div class="header_background">
      <?php
        echo drupal_render($content[field_background]);
      ?>
    </div>
  </div>
  <div class="content header_content" <?php print $content_attributes; ?>>
    <div class="dh_content">
      <div class="header_body">
        <?php
          echo drupal_render($content[field_header_body]);
        ?>
      </div>
      <div class="header_cta">
        <div class="col-md-6">
          <div class="cta_left">
            <div class="cta_icon">
              <?php
                echo drupal_render($content[field_icon]);
              ?>
            </div>
            <div class="cta_text">
              <?php
                echo drupal_render($content[field_text]);
              ?>
            </div>
          </div>
        </div>
        <div class="col-md-6">
          <div class="cta_right">
            <div class="cta_icon">
              <?php
                echo drupal_render($content[field_icon2]);
              ?>
            </div>
            <div class="cta_text">
              <?php
                echo drupal_render($content[field_text2]);
              ?>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>