<?php
 /**
  * This template is used to print a single grouping in a view. It is not
  * actually used in default Views, as this is registered as a theme
  * function which has better performance. For single overrides, the
  * template is perfectly okay.
  *
  * Variables available:
  * - $view: The view object
  * - $grouping: The grouping instruction.
  * - $grouping_level: Integer indicating the hierarchical level of the grouping.
  * - $rows: The rows contained in this grouping.
  * - $title: The title of this grouping.
  * - $content: The processed content output that will normally be used.
  */
?>
<div class="view-grouping year">
  <h3 class="view-grouping-header"><?php print $title; ?></h3>
  <ul class="view-grouping-content">
    <?php
      foreach ($rows as $month) {
        echo '<div class="month">';
          echo '<h3>';
            print $month['group'];
          echo '</h3>';
        echo '</div>';
      }
    ?>
  </ul>
</div>
