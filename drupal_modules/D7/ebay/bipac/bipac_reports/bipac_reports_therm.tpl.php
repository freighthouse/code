<?php

/**
 * @file
 *   Theme template for a thermometer
 *
 * Available variables in the theme include:
 *
 * $count	the endpoint response
 */

  $goal = 100000;
?>

<?php if (!empty($count)): ?>
  <?php
    $count = (int)$count;	// Just making sure
    $percentage = ($count / $goal) * 100;
    if ($percentage > 100) {
      $percentage = 100; //if we surpass the goal we're still not going to let the thermometer get wider than 100%
    }

    if ($count <= ($goal / 2)) {
      $halfway = "goal-under-half";
    } else {
      $halfway = "goal-over-half";
    }
  ?>

  <div class="thermometer-wrapper">
    <div class="thermometer">
      <p class="downloads <?php echo $halfway; ?>" style="width: <?php echo $percentage; ?>%;">
        <span class="downloads-count "><?php print number_format($count) . t(" Downloads"); ?></span>
      </p>
    </div>
  </div>
  <div class="thermometer-goal">
    <h3><?php print t("Goal: ") . number_format($goal); ?></h3>
    <h4>Voter Forms Downloaded</h4>
  </div>
<?php endif; ?>
