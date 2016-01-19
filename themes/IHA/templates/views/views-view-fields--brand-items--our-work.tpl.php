<div class="col-sm-12 col-md-4">
  <div class="brand_our_work">
    <div class="brand_icon_our_work">
      <?php print (!empty($fields['field_icon'])) ?
        $fields['field_icon']->content : '';
      ?>
    </div>
    <div class="brand_title_our_work">
      <?php print (!empty($fields['title_field'])) ?
          $fields['title_field']->content : ''; ?>
    </div>
    <div class="brand_teaser_our_work">
      <?php print (!empty($fields['field_brand_teaser'])) ?
          $fields['field_brand_teaser']->content : ''; ?>
    </div>
  </div>
</div>
