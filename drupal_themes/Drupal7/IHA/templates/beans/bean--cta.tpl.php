<div class="<?php print $classes; ?> clearfix" <?php print $attributes; ?>>
  <div class="cta" <?php print $content_attributes; ?>>
    <div class="row">
      <div class="cta_background">
        <div class="single_cta_content">
          <div class="col-sm-3">
            <div class="cta_left">
              <span class="single_cta_icon">
                <?php
                  echo drupal_render($content["field_cta_icon"]);
                ?>
              </span>
            </div>
          </div>
          <div class="col-sm-9">
            <div class="cta_right">
              <span class="single_cta_date">
                <?php
                  echo drupal_render($content["field_cta_date"]);
                ?>
              </span>
              <span class="single_cta_title">
                <?php
                  echo drupal_render($content["title_field"]);
                ?>
              </span>
              <span class="single_cta_body">
                <?php
                  echo drupal_render($content["field_single_cta_body"]);
                ?>
              </span>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
