<?php

  /**
   * @file
   *   Theme implementation for most pac thermometer
   *
   * Available variables:
   *   - $current
   *   - $max
   *   - $percentage
   *   - $raw_percentage
   */
?>
<?php
   $current = number_format($current);
   $max = number_format($max); 

  if ($raw_percentage > 1) {
    $percentage = '100%';
  }
?>
<h3 class="contr-current"><div class="counter-wrapper"><?php print(t('$') . $current); ?></div></h3>
<div class="contr-therm-wrapper">
  <div class="contr-therm-bar" style="width: <?php echo $percentage; ?>;"></div>
</div>
<p class="goal">Goal: $<?php echo $max; ?></p>