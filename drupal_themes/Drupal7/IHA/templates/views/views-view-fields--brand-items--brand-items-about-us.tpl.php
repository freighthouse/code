<div class="col-xs-12 col-md-2 brand_about_left">
  <div class="brand_icon_about">
    <?php print (!empty($fields['field_icon'])) ?
      $fields['field_icon']->content : ''; ?>
  </div>
</div>
<div class="col-xs-12 col-md-10 brand_about_right">
  <div class="brand_title_about">
    <?php print (!empty($fields['title_field'])) ?
      $fields['title_field']->content : ''; ?>
  </div>
  <div class="brand_text_about">
    <?php print (!empty($fields['field_brand_body'])) ?
      $fields['field_brand_body']->content : ''; ?>
  </div>
</div>
