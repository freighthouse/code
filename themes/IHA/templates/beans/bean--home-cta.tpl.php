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

<div class="<?php print $classes; ?> clearfix" <?php print $attributes; ?>>
  <div class="content" <?php print $content_attributes; ?>>
    <div class="cta_image pull-left col-xs-12 col-sm-6">
      <?php
        echo drupal_render($content["field_cta_image"]);
      ?>
    </div>
    <div class="cta_image pull-right col-xs-12 col-sm-6">
      <?php
        echo drupal_render($content["field_cta_image_right"]);
      ?>
    </div>
    <div class="cta_main">
      <div class="cta_content col-xs-12 col-sm-6">
        <div class="cta_title">
          <?php
            echo drupal_render($content["title_field"]);
          ?>
        </div>
        <div class="cta_body">
          <?php
            echo drupal_render($content["field_cta_body"]);
          ?>
        </div>
        <table class="cta_active_container">
          <tr>
            <td class="cta_active">
              <span class ="cta_icons">
                <?php
                  echo drupal_render($content["field_cta_first_icon"]);
                ?>
              </span>
              <span class="cta_links">
                <?php
                  echo drupal_render($content["field_cta_first_link"]);
                ?>
              </span>
            </td>
            <td class="cta_active">
              <span class ="cta_icons">
                <?php
                  echo drupal_render($content["field_cta_second_icon"]);
                ?>
              </span>
              <span class="cta_links">
                <?php
                  echo drupal_render($content["field_cta_second_link"]);
                ?>
              </span>
            </td>
          </tr>
          <tr>
            <td class="cta_active">
              <span class ="cta_icons">
                <?php
                  echo drupal_render($content["field_cta_third_icon"]);
                ?>
              </span>
              <span class="cta_links">
                <?php
                  echo drupal_render($content["field_cta_third_link"]);
                ?>
              </span>
            </td>
            <td class="cta_active">
              <span class ="cta_icons">
                <?php
                  echo drupal_render($content["field_cta_fourth_icon"]);
                ?>
              </span>
              <span class="cta_links">
                <?php
                  echo drupal_render($content["field_cta_fourth_link"]);
                ?>
              </span>
            </td>
          </tr>
        </table>
      </div>
    </div>
  </div>
</div>
