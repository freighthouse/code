<?php

/**
 * @file
 *   Theme template for BIPAC GOTV
 *
 * Available variables in the theme include:
 *
 * 1) An array of vote $data containing:
 * - StateFullName
 * - CountyFullName
 * - website
 * - reg_address
 * - reg_city
 * - reg_state
 * - reg_zip
 * - reg_phone
 * - reg_fax
 * - abs_address
 * - abs_city
 * - abs_state
 * - abs_zip
 * - abs_phone
 * - abs_fax
 * - StateOfficeURL
 * - CalendarURL
 * - RegFormURL
 * - EarlyVoteFormURL
 * - PollPlaceLink
 * - KeyInfoURL
 * - StateRegAddress1
 * - StateRegAddress2
 * - StateRegCityStateZip
 * 2) An array of date information including:
 * - RegDeadline
 * - EarlyBegin
 * - EarlyEnd
 * - ElectionDate
 * - PrimaryDate
 *
 */
  $state = !empty($data['StateFullName']) ? $data['StateFullName'] : 'Your State';
?>

<?php if (!empty($data)): ?>
  <div class="vote-dates">
    <h4>Your Election Dates:</h4>
    <ul>
      <?php if (!empty($dates['PrimaryDate'])): ?>
        <li><em>Primary:</em> <?php echo $dates['PrimaryDate']; ?></li>
      <?php endif; ?>
      <?php if (!empty($dates['ElectionDate'])): ?>
        <li><em>General:</em> <?php echo $dates['ElectionDate']; ?></li>
      <?php endif; ?>
    </ul>
    <?php if (!empty($data['PollPlaceLink'])): ?>
      <p><a href="<?php echo $data['PollPlaceLink']; ?>" title="Your Polling Place finder" rel="external">Find your polling place</a></p>
    <?php endif; ?>
  </div>

  <div class="vote-accordion vote-tab" id="vote-register">
    <h4 class="vote-accordion-header">
      <a href="#">Register to Vote</a>
    </h4>
    <div class="vote-content">
      <?php if (!empty($data['RegistrationNote'])): ?>
        <?php echo $data['RegistrationNote']; ?>
      <?php endif; ?>
    </div>
  </div>

  <div class="vote-accordion vote-tab" id="vote-early">
    <h4 class="vote-accordion-header">
      <a href="#">Vote Early</a>
    </h4>
    <div class="vote-content">
        <?php if (!empty($dates['EarlyBegin'])): ?>
          <h4>General Early Vote Dates</h4>
          <p><strong>Early Voting Begins:</strong> <?php echo $dates['EarlyBegin']; ?>
          <?php if (!empty($dates['EarlyEnd'])): ?>
            <br/><strong>Early Voting Ends:</strong> <?php echo $dates['EarlyEnd']; ?>
          <?php endif; ?>
          </p>
        
        <?php endif; ?>
        <?php if (!empty($data['EarlyVoteNote'])): ?>
          <h4>Vote Early in Person</h4>
          <p><?php echo $data['EarlyVoteNote']; ?></p>
        <?php endif; ?>
        <?php if (!empty($data['EarlyVoteFormURL'])): ?>
          <h4>Online Early Vote Resources</h4>
          <p><?php echo $state; ?> has <a href="<?php echo $data['EarlyVoteFormURL']; ?>" rel="external">early vote forms</a> available online.</p>
        <?php endif; ?>
      </div>
  </div>

  <div class="vote-accordion vote-offices">
    <h4 class="vote-accordion-header">
      <a href="#">Your Election Offices</a>
    </h4>
    <ul class="vote-content">
      <?php if (!empty($data['reg_address'])): ?>
        <li>
        <h5>Local</h5>
        <p><?php echo $data['reg_address']; ?></p>
        <?php if (!empty($data['reg_city'])): ?>
          <p><?php echo $data['reg_city']; ?>,
        <?php endif; ?>
        <?php if (!empty($data['reg_state'])): ?>
          <?php echo $data['reg_state']; ?>
        <?php endif; ?>
        <?php if (!empty($data['reg_zip'])): ?>
          <?php echo $data['reg_zip']; ?></p>
        <?php endif; ?>
        <?php if (!empty($data['reg_phone'])): ?>
          <p>Phone: <?php echo _bipac_format_phone($data['reg_phone']); ?></p>
        <?php endif; ?>
        </li>
      <?php endif; ?>
      <?php if (!empty($data['StateRegAddress1'])): ?>
        <li>
        <h5>State</h5>
        <p><?php echo $data['StateRegAddress1']; ?>
        <?php if (!empty($data['StateRegAddress2'])): ?>
          <p><?php echo $data['StateRegAddress2']; ?>
        <?php endif; ?>
        <?php if (!empty($data['StateRegCityStateZip'])): ?>
          <p><?php echo $data['StateRegCityStateZip']; ?>
        <?php endif; ?>
        </li>
      <?php endif; ?>
    </ul>
  </div>

  <div class="vote-accordion vote-tab" id="vote-expat">
    <h4 class="vote-accordion-header">
      <a href="#">Living Out of the Country?</a>
    </h4>
    <div class="vote-content">
      <ul>
        <li>The right to vote can be exercised by all United States citizensin every corner of the world. Members of the military, other uniformed services, the Merchant Marine and their eligible family members and all U.S. citizens overseas are able to vote under the Uniformed and Overseas Citizens Absentee Voting Act (UOCAVA)</li>
        <li><em>Who Can Vote Absentee Overseas:</em> Generally, all U.S. citizens 18 years or older who are or will be residing outside the United States during an election period are eligible to vote absentee in any election for Federal office. In addition, all members of the Uniformed Services, their family members and members of the Merchant Marine and their family members, who are U.S. citizens, may vote absentee in Federal, state and local elections.</li>
        <li><em>How to Apply:</em> For detailed information, visit <a href="http://www.fvap.gov/" target="_blank">the website for the Federal Voting Assistance Program</a>, which covers people under the Uniformed and Overseas Citizens Absentee Voting Act.  <br /><br />The Federal Post Card Application (FPCA) is accepted by all states and territories as an application for registration and for absentee ballot. Print and complete the <a href="http://www.fvap.gov/uploads/FVAP/Forms/fpca2013.pdf" rel="external">application</a> (be sure to read the instructions for your state), sign and date it, and mail it (with the proper postage) to your Local Election Official. All States and Territories except American Samoa and Guam accept the FPCA.</li>
      </ul>
      <?php if (!empty($data['abs_address'])): ?>
        <ul>
          <li>
            <?php echo $data['abs_address']; ?>
            <?php if (!empty($data['abs_city'])): ?>
              <p><?php echo $data['abs_city']; ?></p>
            <?php endif; ?>
            <?php if (!empty($data['abs_state'])): ?>
              <p><?php echo $data['abs_state']; ?></p>
            <?php endif; ?>
            <?php if (!empty($data['abs_zip'])): ?>
              <p><?php echo $data['abs_zip']; ?></p>
            <?php endif; ?>
            <?php if (!empty($data['abs_phone'])): ?>
              <p><?php echo _bipac_format_phone($data['abs_phone']); ?></p>
            <?php endif; ?>
            <?php if (!empty($data['abs_fax'])): ?>
              <p><?php echo _bipac_format_phone($data['abs_fax']); ?></p>
            <?php endif; ?>
          </li>
        </ul>
      <?php endif; ?>
    </div>
  </div>
<?php endif; ?>
