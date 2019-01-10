<?php

/**
 * @file
 *   Theme template for BIPAC Officials
 *
 * @args
 *   $official['...
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
 $saved_org = NULL;	// This is used for categorization
?>
<?php if (!empty($officials)): ?>
  <?php $counter = 1; ?>
  <?php foreach ($officials as $type => $official): ?>

    <?php if ($saved_org != $official['position_type'] && $counter != 1): ?>
      </div>
    <?php endif; ?>

    <?php if ($saved_org != $official['position_type']): ?>

     

      <?php
        $organization_string = $official['position_type'];
        $position_type_string_no_space = strtolower (preg_replace('/\s+/', '', $organization_string));
      ?>

      <?php $row_counter = 1; /* row counter reset*/ ?> 
     <div class="organization clearfix <?php print $position_type_string_no_space; ?>">
      <h3><?php echo $official['position_type']; ?></h3>
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

      <?php print '<a class="official-profile-link" href="' . url('official/' . $official['official_id'], array('query' => array('referrer' => 'officials/list'))) . '">' ?>
      <?php if (!empty($official['photo'])): ?>
          <?php echo
            theme('imagecache_external',
              array(
                'path' => $official['photo'],
                'style_name' => 'thumbnail',
                'alt' => $official['full_name'],
                'attributes' => array('class' => 'official-image')
              )
            );
          ?>
      <?php endif; ?>

      <?php if ((!empty($official['official_id'])) && (!empty($official['full_name']))): ?>
          <div class="official-text">
            <?php if (!empty($official['organization'])): ?>
              <p class="official-organization official-subtitle"><?php echo $official['organization']; ?></p>
            <?php endif; ?>

            <?php if (empty($official['organization']) && !empty($official['district'])): ?>
               <p class="official-district official-subtitle"><?php echo $official['district']; ?></p>
            <?php endif; ?>
            <h3 class="official-name">
              <?php echo t($official['full_name']); ?>
              <?php if (!empty($official['party_abbreviation']) && !empty($official ['state_abbreviation'])): ?>
               (<?php echo '<span class="official-party">' . $official['party_abbreviation'] . "-" . $official ['state_abbreviation'] . '</span>'; ?>)
              <?php endif; ?>
            </h3>
          </div>
      <?php endif; ?>
      <?php echo '</a>'; ?>

    </div>
    <?php $counter++; ?>

    <?php $row_counter++; ?>
    <?php $saved_org = $official['position_type']; ?>
  <?php endforeach; ?>

<?php endif; ?>
</div>
