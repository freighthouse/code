<?php

/**
 * @file
 *   Theme template for BIPAC Officials
 *
 * @args
 *   $candidate['...
 *     official_id
 *     full_name
 *     party
 *     party_abbrieviation
 *     photo
 *     position_type
 *     title
 *     organization
 *     state
 *     state_abbreviation
 *     district
 *     district_code
 *     office (theme momentum_officials_address)
 *     social (theme momentum_officials_social)
 *     committees (theme committees)
 *     biography
 *     state_offices (theme momentum_officials_address)
 *     photo (theme imagecache_external)
 *
 * @note
 *   Many of these will be unneeded.
 */
 drupal_add_js('misc/collapse.js');
?>

<div class="official profile-page">

 <div class="official-back-button">
    <a class="official-back-button-link" href="/candidates/list">Back</a>
 </div>

<div class="official-profile-info-wrapper clearfix">
<div class="official-text-wrapper">
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
  
    <div class="official-text">
      <?php if ($incumbent == 'Y'): ?>
        <p class="official-organization official-subtitle"><?php echo "Incumbent"; ?></p>
      <?php endif; ?>

      <h3 class="official-name"><?php echo $full_name; ?>
      <?php echo '<span class="official-party">('; ?>
        <?php if (!empty($party_abbreviation)): ?>
         <?php echo $party_abbreviation;?>
        <?php endif; ?>
      <?php echo ')</span>'; ?>
      </h3>
      <div class="official-district">
         <?php if (!empty($district)): ?>
          <?php echo ("District: " . $district); ?>
        <?php endif; ?>
      </div>
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
        <div class=" official-subtitle"><?php print "Biography"; ?></div>
          <ul class="officials-bio-list">
            <?php if (!empty($party)): ?>
              <li class="officials-bio-list-item">
                <strong>Party: </strong>
                <?php echo $party; ?>
              </li>
            <?php endif; ?>

            <?php if (!empty($election_details)): ?>
              <li class="officials-bio-list-item">
                <strong>Election Details: </strong>
                <?php echo $election_details; ?>
              </li>
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
                <?php echo $seniority; ?>
              </li>
            <?php endif; ?>

            <?php if (!empty($terms_served)): ?>
              <li class="officials-bio-list-item">
                <strong>Seniority: </strong>
                <?php echo $terms_served; ?>
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
                <li class="officials-committees-list-item committee-<?php echo $committee_count; ?>">
                  <?php echo theme('momentum_officials_committees', $committee); ?>
                </li>
                <?php $committee_count++; ?>
              <?php endforeach; ?>
            </ul>
            <div class="officials-show-button">Show All</div>
            <div class="officials-hide-button officials-hidden">Hide</div>
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
    <div class=" official-subtitle"><?php print "Campaign Office"; ?></div>
    <?php if (!empty($office)): ?>
      <?php echo theme('momentum_officials_address', $office); ?>
    <?php endif; ?>

    <?php if (!empty($state_offices)): ?>
      <?php $offices_content = NULL; ?>
      <?php foreach ($state_offices as $office): ?>
        <?php $offices_content .= theme('momentum_officials_address', $office); ?>
      <?php endforeach; ?>
      <?php echo theme('ctools_collapsible', array('handle' => '<h3 class="ctools-collapsible-title">' . t('State Offices') . '</h3>', 'content' => $offices_content, 'collapsed' => TRUE)); ?> 
    <?php endif; ?>

    <?php if (!empty($staffers)): ?>
      <?php $staffers_content = NULL; ?>
      <?php foreach ($staffers as $staffer): ?>
        <?php $staffers_content .= theme('momentum_officials_staffers', $staffer); ?>
      <?php endforeach; ?>
      <?php echo theme('ctools_collapsible', array('handle' => '<h3 class="ctools-collapsible-title">' . t('Staffers') . '</h3>', 'content' => $staffers_content, 'collapsed' => TRUE)); ?> 
    <?php endif; ?>

  </div>
</div>
