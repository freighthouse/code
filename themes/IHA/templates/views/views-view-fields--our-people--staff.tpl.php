<div>
  <div class="our_people_row">
    <div class="our_people_profile_pic col-xs-4">
      <?php print (!empty($fields['field_profile_picture'])) ?
        $fields['field_profile_picture']->content : ''; ?>
    </div>
    <div class="our_people_info col-xs-8">
      <div class="our_people_name">
        <?php print (!empty($fields['field_name'])) ?
          $fields['field_name']->content : ''; ?>
      </div>
      <div class="our_people_title">
        <?php print (!empty($fields['field_user_title'])) ?
          $fields['field_user_title']->content : ''; ?>
      </div>
    </div>
  </div>
</div>
