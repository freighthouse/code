<?php

/**
 * @file
 *   Committee template for Momentum Officials
 *
 * @args
 *   $committee_chamber
 *   $committee_type
 *   $title
 *   $name
 */
 //krumo($title,$committee_chamber, $committee_type);
?>

  <span class="officials-committees-name">

  <?php if ($committee_type != 'Senate Subcommittee' && $committee_type !='House Subcommittee'): ?>
    <?php if (!empty($name)): ?>
      <?php print $name; ?>    
    <?php endif; ?>
    <?php endif; ?>
  </span>

<?php if($title == 'Ranking Member') echo '<span>**</span>' ; ?>
<?php if($title == 'Ranking Minority Member') echo '<span>**</span>' ; ?>
<?php if($title == 'Chairman') echo '<span>*</span>' ; ?>



