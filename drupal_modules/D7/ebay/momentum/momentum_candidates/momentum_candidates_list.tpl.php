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
 $saved_org = NULL; // This is used for categorization
//dsm($candidates, 'candidates');
?>
<?php if (!empty($candidates)): ?>
  <p>* indicates the incumbent</p>
  <?php $counter = 1; ?>
  <?php foreach ($candidates as $type => $candidate): ?>

    <?php if ($saved_org != $candidate['organization'] && $counter != 1): ?>
      </div>
    <?php endif; ?>

    <?php if ($saved_org != $candidate['organization']): ?>

     

      <?php
        $organization_string = $candidate['organization'];
        $position_type_string_no_space = strtolower (preg_replace('/\s+/', '', $organization_string));
      ?>

      <?php $row_counter = 1; /* row counter reset*/ ?> 
     <div class="organization clearfix <?php print $position_type_string_no_space; ?>">
      <h3><?php echo $candidate['organization']; ?></h3>
    <?php endif; ?>

    <?php
      if ($row_counter % 2 == 0) {
        $counter_style = 'row-' . $row_counter . ' row-even';
      }
      else {
        $counter_style = 'row-' . $row_counter . ' row-odd';
      }
    ?>
    <div class="official <?php print $counter_style; ?>">

      <?php print '<a class="official-profile-link" href="' . url('candidate/' . $candidate['official_id'], array('query' => array('referrer' => 'candidates/list'))) . '">' ?>
      <?php if (!empty($candidate['photo'])): ?>
          <?php echo
            theme('imagecache_external',
              array(
                'path' => $candidate['photo'],
                'style_name' => 'thumbnail',
                'alt' => $candidate['full_name'],
                'attributes' => array('class' => 'official-image')
              )
            );
          ?>
      <?php endif; ?>

      <?php if ((!empty($candidate['official_id'])) && (!empty($candidate['full_name']))): ?>
          <div class="official-text">
            <?php if (!empty($candidate['organization'])): ?>
              <p class="official-organization official-subtitle"><?php echo $candidate['organization']; ?></p>
            <?php endif; ?>

            <?php if (empty($candidate['organization']) && !empty($candidate['district'])): ?>
               <p class="official-district official-subtitle"><?php echo $candidate['district']; ?></p>
            <?php endif; ?>
            <h3 class="official-name">
              <?php echo t($candidate['full_name']); ?>
              <?php if (!empty($candidate['party'])): ?>
               <?php echo '<br><span class="candidate-party">(' . $candidate['party'] . ')</span>'; ?>
              <?php endif; ?>
              <?php if ($candidate['incumbent'] == 'Y') echo "*"; ?>
            </h3>
          </div>
      <?php endif; ?>
      <?php echo '</a>'; ?>

    </div>
    <?php $counter++; ?>

    <?php $row_counter++; ?>
    <?php $saved_org = $candidate['organization']; ?>
  <?php endforeach; ?>

<?php endif; ?>
</div>
