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
?>

<?php if (!empty($officials)): ?>

  <?php foreach ($officials as $type => $official): ?>

    <?php if ((!empty($official['official_id'])) && (!empty($official['full_name']))): ?>

      <div id="official_<?php echo $official['official_id']; ?>">

        <h3><?php echo $official['full_name']; ?></h3>

        <ul>
          <?php if (!empty($official['photo'])): ?><?php echo theme('imagecache_external', array('path' => $official['photo'], 'style_name' => 'thumbnail', 'alt' => $official['full_name'])); ?><?php endif; ?>
          <?php if (!empty($official['party'])): ?><li><em>Party:</em> <?php echo $official['party']; ?></li><?php endif; ?>
          <?php if (!empty($official['party_abbrieviation'])): ?><li><em>Party Abbrieviation:</em> <?php echo $official['party_abbrieviation']; ?></li><?php endif; ?>
          <?php if (!empty($official['position_type'])): ?><li><em>Position:</em> <?php echo $official['position_type']; ?></li><?php endif; ?>
          <?php if (!empty($official['title'])): ?><li><em>Title:</em> <?php echo $official['title']; ?></li><?php endif; ?>
          <?php if (!empty($official['organization'])): ?><li><em>Organization:</em> <?php echo $official['organization']; ?></li><?php endif; ?>
          <?php if (!empty($official['state'])): ?><li><em>State:</em> <?php echo $official['state']; ?></li><?php endif; ?>
          <?php if (!empty($official['state_abbreviation'])): ?><li><em>State Abbreviation:</em> <?php echo $official['state_abbreviation']; ?></li><?php endif; ?>
          <?php if (!empty($official['district'])): ?><li><em>District:</em> <?php echo $official['district']; ?></li><?php endif; ?>
          <?php if (!empty($official['district_code'])): ?><li><em>District Code:</em> <?php echo $official['district_code']; ?></li><?php endif; ?>
          <?php if (!empty($official['social'])): ?><li><em>Social:</em> <?php echo theme('momentum_officials_social', $official['social']); ?></li><?php endif; ?>
          <?php if (!empty($official['office'])): ?><li><em>Office:</em> <?php echo theme('momentum_officials_address', $official['office']); ?></li><?php endif; ?>
          <?php if (!empty($official['committees'])): ?>
            <?php foreach ($official['committees'] as $committee): ?>
              <?php echo theme('momentum_officials_committees', $committee); ?>
            <?php endforeach; ?>
          <?php endif; ?>
          <?php if (!empty($official['state_offices'])): ?>
            <?php foreach ($official['state_offices'] as $office): ?>
              <?php echo theme('momentum_officials_address', $office); ?>
            <?php endforeach; ?>
          <?php endif; ?>
          <?php if (!empty($official['biography'])): ?><li><em>Biography:</em> <pre><?php echo $official['biography']; ?></pre></li><?php endif; ?>
        </ul>

    </div>

    <?php endif; ?>

  <?php endforeach; ?>

<?php endif; ?>
