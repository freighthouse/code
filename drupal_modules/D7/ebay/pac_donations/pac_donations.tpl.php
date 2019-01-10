<?php

  /**
   * @file
   *   Theme implementation for most pac thermometer
   *
   * Available variables:
   *   - $current
   *   - $percentage
   *   - $raw_percentage
   *   - $max
   */

  if ($raw_percentage > 1) {
    $percentage = '100%';
  }
?>

<h3 class="charitable-current"><?php echo $current; ?></h3>
<div class="charitable-therm-wrapper">
  <div class="charitable-therm-bar" style="width: <?php echo $percentage; ?>;"></div>
</div>
<div class="charitable-therm-accents"></div>
<?php echo $max; ?>