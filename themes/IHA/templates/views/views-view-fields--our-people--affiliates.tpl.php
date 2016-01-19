<div>
  <div class="our_members_row">
    <div class="our_members_profile_pic col-xs-4">
      <?php print (!empty($fields['field_affiliate_picture'])) ?
        $fields['field_affiliate_picture']->content : ''; ?>
    </div>
    <div class="our_members_info col-xs-6">
      <div class="our_members_name">
      <?php print (!empty($fields['field_affiliate_member_name'])) ?
        $fields['field_affiliate_member_name']->content : ''; ?>
      </div>
      <div class="our_members_title">
        <?php print (!empty($fields['field_organization_title'])) ?
        $fields['field_organization_title']->content : ''; ?>
      </div>
      <div class="our_members_link">
        <?php print (!empty($fields['field_organization_link'])) ?
        $fields['field_organization_link']->content : ''; ?>
      </div>
      <div class="our_members_role">
        <?php print (!empty($fields['field_committee_role'])) ?
          $fields['field_committee_role']->content : ''; ?>
      </div>
    </div>
  </div>
</div>
