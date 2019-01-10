<?php

/**
 * @file
 *   Theme template for BIPAC GOTV
 *
 * Available variables in the theme include:
 *
 * An array of vote $data containing:
 *   state_full
 *   state
 *   state_office
 *   registration_form
 *   early_vote_form
 *   polling_place
 *   voter_id
 *   registration_address
 *   registration_city
 *   registration_state
 *   registration_zip
 *   registration_phone
 *   registration_note
 *   early_vote_note
 *   state_registration_address
 *   state_registration_city_state
 *   primary_registration_deadline
 *   primary_absentee_application_deadline
 *   primary_absentee_return_deadline
 *   primary_early_vote_begin
 *   primary_early_vote_end
 *   primary_election_day
 *   general_registration_deadline
 *   general_absentee_application_deadline
 *   general_absentee_return_deadline
 *   general_early_vote_begin
 *   general_early_vote_end
 *   general_election_day
 *
 */
?>
<?php if (!empty($state_full)): ?>
  <h3 class="vote-response--state"><?php echo $state_full; ?> Election Dates</h3>
  <div class="vote-general-info">

  <ul class="election-date-list">
          <?php if ((!empty($primary_registration_deadline )) && ($primary_registration_deadline != '0000-00-00')): ?>
            <?php $originalDate = strtotime($primary_registration_deadline); ?>
              <?php $full_date = date('M j', $originalDate); ?>
              <li class="election-date-list-item">
                <div class="election-date"><?php echo $full_date; ?></div>
                <div class="election-title">Primary Voter Registration Deadline</div>
              </li>
              <?php unset($full_date); ?>
          <?php endif; ?> 

          <?php if ((!empty($primary_election_day)) && ($primary_election_day != '0000-00-00')): ?>
            <?php $originalDate = strtotime($primary_election_day); ?>
              <?php $full_date = date('M j', $originalDate); ?>
              <li class="election-date-list-item">
                <div class="election-date"><?php echo $full_date; ?></div>
                <div class="election-title">Primary Election Day</div>
              </li>
              <?php unset($full_date); ?>
          <?php endif; ?> 

          <?php if ((!empty($general_registration_deadline)) && ($general_registration_deadline != '0000-00-00')): ?>
            <?php $originalDate = strtotime($general_registration_deadline); ?>
              <?php $full_date = date('M j', $originalDate); ?>            
              <li class="election-date-list-item">
                <div class="election-date"><?php echo $full_date; ?></div>
                <div class="election-title">General Election Registration Deadline</div>
              </li>
              <?php unset($full_date); ?>
          <?php endif; ?> 

          <?php if ((!empty($general_election_day)) && ($general_election_day != '0000-00-00')): ?>
            <?php $originalDate = strtotime($general_election_day); ?>
              <?php $full_date = date('M j', $originalDate); ?>             
              <li class="election-date-list-item">
                <div class="election-date"><?php echo $full_date; ?></div>
                <div class="election-title">General Election Day</div>
              </li>
              <?php unset($full_date); ?>
          <?php endif; ?> 
    </ul>

      <?php if (!empty($polling_place)): ?>
        <p><a href="<?php echo $polling_place; ?>" target="_blank" title="Your Polling Place finder" rel="external" target="_blank" class="polling-place-link">Find your polling place</a></p>
      <?php endif; ?>
    </div>
  </div>

  <div class="vote-accordion-wrapper">

    <div class="vote-accordion vote-tab" id="vote-register">
      <h3 class="vote-accordion-header">
        <a href="#">Register to Vote</a>
      </h3>
      <div class="vote-content">

          <?php if ((!empty($primary_registration_deadline)) && ($primary_registration_deadline != '0000-00-00')): ?>
            <?php $originalDate = strtotime($primary_registration_deadline); ?>
              <?php $full_date = date('M j', $originalDate); ?>
            <h4>Primary Registration Deadline: <?php echo $full_date; ?></h4>
            <?php unset($full_date); ?>
        <?php endif; ?>

          <?php if ((!empty($general_registration_deadline)) && ($general_registration_deadline != '0000-00-00')): ?>
              <?php $originalDate = strtotime($general_registration_deadline); ?>
              <?php $full_date = date('M j', $originalDate); ?>            
            <h4>General Registration Deadline: <?php echo $full_date; ?></h4>
        <?php endif; ?>

        <?php if (!empty($registration_note)): ?>
          <p><span class="bold">Note:</span> You may register at your precinct's polling place on Election Day and cast a special ballot that same day.</p>
          <?php echo $registration_note; ?>
        <?php endif; ?>
      </div>
    </div>

    <div class="vote-accordion vote-tab" id="vote-early">
      <h3 class="vote-accordion-header">
        <a href="#">Vote Early or Absentee</a>
      </h3>
      <div class="vote-content">
        <div class="clearfix">
          <div class="early-vote-wrapper">
         <!--  <?php if (!empty($primary_registration_deadline)): ?>
            <?php $originalDate = strtotime($primary_registration_deadline); ?>
              <?php $full_date = date('M j', $originalDate); ?>
            <h4>Primary Registration Deadline: <?php echo $full_date; ?></h4>
            <?php unset($full_date); ?>
        <?php endif; ?> -->

          <ul class="early-election-list">
            <?php if (!empty($primary_absentee_application_deadline)): ?>
              <?php $originalDate = strtotime($primary_absentee_application_deadline); ?>
              <?php $full_date = date('M j', $originalDate); ?>
              <li class="early-election-item">
                <div class="early-election-title">Primary Absentee Application Deadline: <?php echo $full_date; ?></div>
              </li>
            <?php endif; ?>

            <?php if (!empty($primary_absentee_return_deadline)): ?>
              <?php $originalDate = strtotime($primary_absentee_return_deadline); ?>
              <?php $full_date = date('M j', $originalDate); ?>              
              <li class="early-election-item">
                <div class="early-election-title">Primary Absentee Return Deadline: <?php echo $full_date; ?></div>
              </li>
              <?php unset($full_date); ?>
            <?php endif; ?>
          </ul>
          </div>
          
          <div class="early-vote-wrapper">
<!--           <?php if (!empty($general_registration_deadline)): ?>
              <?php $originalDate = strtotime($general_registration_deadline); ?>
              <?php $full_date = date('M j', $originalDate); ?>            
            <h4>General Registration Deadline: <?php echo $full_date; ?></h4>
            <?php unset($full_date); ?>
        <?php endif; ?> -->

          <ul class="early-election-list">
            <?php if (!empty($general_absentee_application_deadline)): ?>
              <?php $originalDate = strtotime($general_absentee_application_deadline); ?>
              <?php $full_date = date('M j', $originalDate); ?> 
              <li class="early-election-item">
                <div class="early-election-title">General Absentee Application Deadline: <?php echo $full_date; ?></div>
              </li>
              <?php unset($full_date); ?>
            <?php endif; ?>

            <?php if (!empty($general_absentee_return_deadline)): ?>
              <?php $originalDate = strtotime($general_absentee_return_deadline); ?>
              <?php $full_date = date('M j', $originalDate); ?> 
              <li class="early-election-item">
                <div class="early-election-title">General Absentee Return Deadline: <?php echo $full_date; ?></div>
              </li>
              <?php unset($full_date); ?>
            <?php endif; ?>
          </ul>
          </div>

          <?php if (!empty($early_vote_note)): ?>
          <h4>Vote Early in Person</h4>
            <p><?php echo $early_vote_note; ?></p>
          <?php endif; ?>

        <div class="early-vote-wrapper">
          <ul class="early-election-list">
            <?php if ((!empty($primary_early_vote_begin)) && ($primary_early_vote_begin != '0000-00-00')): ?>
              <?php $originalDate = strtotime($primary_early_vote_begin); ?>
              <?php $full_date = date('M j', $originalDate); ?>
              <li class="early-election-item">
                <div class="early-election-title">Early Voting Begins: <?php echo $full_date; ?></div>
              </li>
              <?php unset($full_date); ?>
            <?php endif; ?>
            <?php if ((!empty($primary_early_vote_end)) && ($primary_early_vote_end != '0000-00-00')): ?>
              <?php $originalDate = strtotime($primary_early_vote_end); ?>
              <?php $full_date = date('M j', $originalDate); ?>
              <li class="early-election-item">
                <div class="early-election-title">Early Voting Ends: <?php echo $full_date; ?></div>
              </li>
              <?php unset($full_date); ?>
            <?php endif; ?>
          </ul>
        </div>
      </div>
        <h4>Vote Early by Mail</h4>
        <p>You must submit an application for an absentee ballot to the counter clerk. Your application must be received no later than 7 days before election day. you voted ballot must be received by the county clerk no later than the close of polls on election day.</p>
        <p>Registration Address</p>
        <p>
          <?php echo $registration_address; ?><br/>
          <?php if ($registration_city == 'Washington, DC'): ?>
            <?php echo 'Washington'; ?>,&nbsp;
          <?php else: ?>
            <?php echo $registration_city; ?>,&nbsp
          <?php endif; ?>
          <?php echo $registration_state; ?>&nbsp<?php echo$registration_zip; ?><br/>
          Phone: <?php echo momentum_format_phone($registration_phone); ?><br/>
        </p>
        <?php if (!empty($early_vote_form)): ?>
          <h4>Online Early Vote Resources</h4>
          <p><?php echo $state_full; ?> has <a href="<?php echo $early_vote_form; ?>" rel="external" target="_blank">early vote forms</a> available online.</p>
        <?php endif; ?>
      </div>
    </div>

    <div class="vote-accordion vote-offices">
      <h3 class="vote-accordion-header">
        <a href="#">Your Election Offices</a>
      </h3>
      <div class="vote-content vote-election-offices">
        <?php if (!empty($registration_address)): ?>
          <h4>Local</h4>
          <p><?php echo $registration_address; ?>

          <?php if ($registration_city == 'Washington, DC'): ?>
            <br /><?php echo 'Washington'; ?>
            <?php if (!empty($registration_state)): ?>, <?php endif; ?>
          <?php else: ?>
            <br /><?php echo $registration_city; ?>
            <?php if (!empty($registration_state)): ?>, <?php endif; ?>
          <?php endif; ?>
          <?php if (!empty($registration_state)): ?>
            <?php echo $registration_state; ?>
          <?php endif; ?>
          <?php if (!empty($registration_zip)): ?>
            <?php echo $registration_zip; ?>
          <?php endif; ?>
          <?php if (!empty($registration_phone)): ?>
            <br/>Phone: <?php echo momentum_format_phone($registration_phone); ?>
          <?php endif; ?>
          </p>
        <?php endif; ?>
        <?php if (!empty($state_registration_address)): ?>
          <h4>State</h4>
          <p><?php echo $state_registration_address; ?>
          <?php if (!empty($state_registration_city_state )): ?>
            <br/><?php echo $state_registration_city_state ; ?>
          <?php endif; ?>
          </p>
        <?php endif; ?>
      </div>
    </div>

    <div class="vote-accordion vote-tab" id="vote-expat">
      <h3 class="vote-accordion-header">
        <a href="#">Living Out of the Country?</a>
      </h3>
      <div class="vote-content">
        <ul>
          <li>The right to vote can be exercised by all United States citizens in every corner of the world. Members of the military, other uniformed services, the Merchant Marine and their eligible family members and all U.S. citizens overseas are able to vote under the Uniformed and Overseas Citizens Absentee Voting Act (UOCAVA)</li>
          <li><em>Who Can Vote Absentee Overseas:</em> Generally, all U.S. citizens 18 years or older who are or will be residing outside the United States during an election period are eligible to vote absentee in any election for Federal office. In addition, all members of the Uniformed Services, their family members and members of the Merchant Marine and their family members, who are U.S. citizens, may vote absentee in Federal, state and local elections.</li>
          <li><em>How to Apply:</em> For detailed information, visit <a href="http://www.fvap.gov/" target="_blank">the website for the Federal Voting Assistance Program</a>, which covers people under the Uniformed and Overseas Citizens Absentee Voting Act.  <br /><br />The Federal Post Card Application (FPCA) is accepted by all states and territories as an application for registration and for absentee ballot. Print and complete the <a href="http://www.fvap.gov/uploads/FVAP/Forms/fpca2013.pdf" rel="external" target="_blank">application</a> (be sure to read the instructions for your state), sign and date it, and mail it (with the proper postage) to your Local Election Official. All States and Territories except American Samoa and Guam accept the FPCA.</li>
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
                <p><?php echo momentum_format_phone($data['abs_phone']); ?></p>
              <?php endif; ?>
              <?php if (!empty($data['abs_fax'])): ?>
                <p><?php echo momentum_format_phone($data['abs_fax']); ?></p>
              <?php endif; ?>
            </li>
          </ul>
        <?php endif; ?>
      </div>
    </div>
  </div> <!-- end vote accordion wrapper -->
<?php else: ?>
  <div class="vote-nostate"><h1>Find Your Voting Information</h1></div>
  <div class="vote-noresults">
    <p><strong>We are a nation of many voices, and on Election Day, every voice counts!</strong></p>
    <p>Get information and application forms for early voting, absentee voting, overseas voting, and voter registration.  Start by entering your five digit zip code into the form above.</p>
    <p>(If you are currently living overseas, enter the zip code for your last residence in the United States.)</p>
  </div>
<?php endif; ?>
