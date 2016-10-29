<div>
  <div class="our_members_row">
    <div class="our_members_profile_pic col-xs-4">
      <?php print (!empty($fields['field_committee_picture'])) ?
        $fields['field_committee_picture']->content : ''; ?>
    </div>
    <div class="our_members_info col-xs-8">
      <div class="our_members_name">
        <?php print (!empty($fields['field_committee_member_name'])) ?
          $fields['field_committee_member_name']->content : ''; ?>
      </div>
      <div class="our_members_title">
        <?php print (!empty($fields['field_committee_title'])) ?
          $fields['field_committee_title']->content : ''; ?>
      </div>
      <div class="our_members_link">
        <?php print (!empty($fields['field_organization_name'])) ?
          $fields['field_organization_name']->content : ''; ?>
      </div>
      <div class="our_members_role">
        <?php print (!empty($fields['field_committee_role'])) ?
          $fields['field_committee_role']->content : ''; ?>
      </div>
    </div>
  </div>
</div>
