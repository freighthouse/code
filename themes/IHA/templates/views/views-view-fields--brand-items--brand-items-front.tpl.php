<div class ="col-sm-4 col-xs-12">
  <div class="front_page_brand">
    <a href="our-work">
      <div class="brand_icon_front">
        <?php print (!empty($fields['field_icon'])) ?
          $fields['field_icon']->content : ''; ?>
      </div>
      <div class="brand_title_front">
        <?php print (!empty($fields['title_field'])) ?
          $fields['title_field']->content : ''; ?>
      </div>
      <div class="brand_teaser_front">
        <?php print (!empty($fields['field_brand_teaser'])) ?
          $fields['field_brand_teaser']->content : ''; ?>
      </div>
    </a>
  </div>
</div>
