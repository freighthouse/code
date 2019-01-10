<?php

/**
 * @file
 *   Theme template for BIPAC Officials
 *
 * @args
 *   full_name
 *   party
 *   party_abbrieviation
 *   photo
 *   position_type
 *   title
 *   organization
 *   state
 *   state_abbreviation
 *   district
 *   district_code
 *   office (theme momentum_officials_address)
 *   social (theme momentum_officials_social)
 *   state_offices (theme momentum_officials_address)
 *   seniority
 *   terms_served
 *   next_election
 *   relection_status
 *   election_details
 *
 * @note
 *   Many of these will be unneeded.
 */
 drupal_add_js('misc/collapse.js');
 global $base_url;
  /**
   * $full_name = !empty($full_name) ? $full_name : 'Apple P. Orange';
   * $party = !empty($party) ? $party : 'Fruit';
   * $party_abbreviation = !empty($party_abbreviation) ? $party_abbreviation : 'F';
   * $position_type = !empty($position_type) ? $position_type : 'Type';
   * $title = !empty($title) ? $title : 'Tangerine';
   * $organization = !empty($organization) ? $organization : 'Senate';
   * $state = !empty($state) ? $state : 'Frutopia';
   * $state_abbreviation = !empty($state_abbreviation) ? $state_abbreviation : 'FP';
   * $district = !empty($district) ? $district : 'District 11';
   * $district_code = !empty($district) ? $district : 'FP-11';
   * $seniority = !empty($seniority) ? $seniority : '77';
   * $terms_served = !empty($terms_served) ? $terms_served : '99';
   * $next_election = !empty($election_status) ? $election_status : '2092';
   * $relection_status = !empty($relection_status) ? $relection_status : 'Ready for picking.';
   * $election_details = !empty($election_details) ? $election_details : 'Ripe';
   */
?>

<div class="official profile-page">

 <div class="official-back-button">
    <a class="official-back-button-link" href="/officials/list">Back</a>
 </div>

<div class="official-profile-info-wrapper clearfix">
  <?php if (!empty($photo)): ?>
    <?php echo
      theme('imagecache_external',
        array(
          'path' => $photo,
          'style_name' => 'thumbnail',
          'alt' => $full_name,
          'attributes' => array('class' => 'official-image')
        )
      );
    ?>
  <?php endif; ?>

    <div class="officia-intro-wrapper">
      <div class="official-text">
        <?php if (!empty($organization)): ?>
          <p class="official-organization official-subtitle"><?php echo $organization; ?></p>
        <?php endif; ?>
        <?php /*
        <?php if (!empty($district)): ?>
          <p class="official-district  official-subtitle"><?php echo $district; ?></p>
        <?php endif; ?>
        */; ?>
        <h3 class="official-name"><?php echo $full_name; ?> 
        <?php if (!empty($party_abbreviation)): ?>
          <?php echo '(<span class="official-party">' . $party_abbreviation; ?>
          <?php if(!empty($state_abbreviation)): echo '- ' . $state_abbreviation; ?>
            <?php endif; ?>
            <?php echo '</span>)'; ?>
        <?php endif; ?>
        </h3>
      </div>

      <div class="officials-social-wrapper">
        <?php if (!empty($social)): ?>
          <?php echo theme('momentum_officials_social', $social); ?>
        <?php endif; ?>
      </div>
    </div>
  </div>

  <div class="official-full-text">

    <div class="officials-info-wrapper">
      <div class="officials-info-content">
        <div class="officials-bio-wrapper">
        <div class="official-subtitle">
          <?php if ((!empty($party) || !empty($election_details) || !empty($next_election) || !empty($seniority) || !empty($terms_served))): ?>
          <?php print 'Biography'; ?></div>
          <?php endif; ?>

          <ul class="officials-bio-list">
            <?php if (!empty($party)): ?>
              <li class="officials-bio-list-item">
                <strong>Party: </strong>
                <?php echo $party; ?>
              </li>
            <?php endif; ?>

            <?php if (!empty($district)): ?>
              <li class="officials-bio-list-item">
                <strong>District: </strong>
                <?php echo $district; ?>
              </li>
            <?php endif; ?>

            <?php if (!empty($election_details)): ?>
                <?php preg_match('(\d\d\S\s[a-z].*)', $election_details, $matches); $last_results = $matches; ?>
                <?php preg_match('(\d\d\d\d)', $election_details, $matches); $first_elected = $matches; ?>
              
              <?php if (!empty($last_results)): ?> 
                <li class="officials-bio-list-item">       
                  <strong>Last Election Results: </strong>
                  <?php echo $last_results[0]; ?>
                </li>
              <?php endif; ?>

              <?php if (!empty($first_elected)): ?> 
                <li class="officials-bio-list-item">
                  <strong>First Elected: </strong>
                  <?php echo $first_elected[0]; ?>
                </li> 
              <?php endif; ?>

            <?php endif; ?>

            <?php if (!empty($next_election)): ?>
              <li class="officials-bio-list-item">
                <strong>Next Election: </strong>
                <?php echo $next_election; ?>
              </li>
            <?php endif; ?>
            <?php if (!empty($seniority)): ?>
              <li class="officials-bio-list-item">
                <strong>Seniority: </strong>
                <?php echo $seniority . '; ' . $terms_served; ?>
              </li>
            <?php endif; ?>
          </ul>
        </div>

       
        <div class="officials-committees-wrapper">
        <?php if (!empty($committees)): ?>
          <div class=" official-subtitle"><?php print "Committees"; ?></div>
            <?php $committee_count = 0; ?>
            <ul class="officials-committees-list">
              <?php foreach ($committees as $committee): ?>
                <?php if ($committee['committee_type'] != 'Senate Subcommittee' && $committee['committee_type'] != 'House Subcommittee'): ?>
                <li class="officials-committees-list-item committee"> <!-- add -<?php /*echo $committee_count*/; ?> for counter -->
                  <?php echo theme('momentum_officials_committees', $committee); ?>
                </li>
                <?php $committee_count++; ?>
                <?php endif; ?>
              <?php endforeach; ?>
            </ul>
            <div class="committee-footnote">* Chair </div>
            <div class="committee-footnote">** Ranking Member </div>
<!--             <div class="officials-show-button">Show All</div>
            <div class="officials-hide-button officials-hidden">Hide</div> -->
          <?php endif; ?>
        </div>
      </div>
    </div>

    <?php /*
    <?php if (!empty($state)): ?>
      <p class="official-state"><?php echo $state; ?></p>
    <?php endif; ?>

    <?php if (!empty($party)): ?>
      <p class="official-party"><?php echo $party; ?></p>
    <?php endif; ?>
    */; ?>

    <?php if (!empty($office)): ?>
      <?php echo theme('momentum_officials_address', $office); ?>
    <?php endif; ?>

    <?php if (!empty($state_offices)): ?>
      <?php $offices_content = NULL; ?>
      <?php foreach ($state_offices as $office): ?>
        <?php $offices_content .= theme('momentum_officials_address', $office); ?>
      <?php endforeach; ?>
      <?php echo theme('ctools_collapsible', array('handle' => '<h3 class="ctools-collapsible-title">' . t('District Offices') . '</h3>', 'content' => $offices_content, 'collapsed' => TRUE)); ?> 
    <?php endif; ?>

    <?php if (!empty($staffers)): ?>
      <?php $staffers_content = NULL; ?>
      <?php foreach ($staffers as $staffer): ?>
        <?php $staffers_content .= theme('momentum_officials_staffers', $staffer); ?>
      <?php endforeach; ?>
      <?php echo theme('ctools_collapsible', array('handle' => '<h3 class="ctools-collapsible-title">' . t('Staff') . '</h3>', 'content' => $staffers_content, 'collapsed' => TRUE)); ?> 
    <?php endif; ?>

    

  </div>



   <div>
    <?php if (!empty($vote_record['votes'])): ?>
    <h3>Vote Record</h3>
        
      <?php foreach ($vote_record['votes'] as $vote): ?>
        <?php $clean_position = strtolower($vote['legislator']['Vote']); ?>
      <div class="vote-data-wrapper">
         <div class="bill-name"><span class="bold"><?php echo $vote['bill_data']['BillName']; ?> </span></div>
          <div class="question"><?php echo $vote['Motion']; ?></div>
          <div class="vote-position <?php echo $clean_position; ?>"><span class="visuallyhidden">
            Position: <?php echo $vote['legislator']['Vote']; ?></span></div>
        <ul class="vote-list">
          <li class="vote-list-item session"><span class="bold"> Session: </span><?php echo $vote['bill_data']['IntroducedSession']; ?></li>
          <li class="vote-list-item vote-date"><span class="bold"> Vote Date: </span><?php echo $vote['VoteDate']; ?></li>
          <li class="vote-list-item preferred-position"><span class="bold">Preferred Position: </span><?php echo $vote['mbr_position']; ?></li>
          <li class="vote-list-item vote-details-back"><a href="<?php echo $base_url.'/vote-record/'.$vote['bill_data']['BillID'].'/'.$vote['VoteId']; ?>">Vote Details...</a></li>
        </ul>
          

        </div>
      <?php endforeach; ?>
    <?php endif; ?>

   </div>

</div>
