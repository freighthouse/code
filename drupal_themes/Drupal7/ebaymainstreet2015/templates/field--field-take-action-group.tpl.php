<?php
  if (count($items) == 1) {
    $single_item = ' single-item';
  }
  elseif (count($items) == 3) {
      $single_item = ' triple-item';
  }
  elseif (count($items) == 2) {
      $single_item = ' double-item';
  }
?>

<div class="all-take-action-wrapper<?php print $single_item; ?>">
<?php foreach ($items as $delta => $item): ?>
  <?php if (isset($item['entity'])): //because this stupid tpl will carry on down through all the child fields otherwise ?>
    <?php foreach ($item['entity']['field_collection_item'] as $key => $value): ?>
      <?php
        $rownum = $delta + 1;
        if ($rownum % 2 == 0) {
          $row_type = 'even';
        }
        else {
          $row_type = 'odd';
        }

        // Get the title
        if (isset($value['field_take_action_text']['#items'][0]['safe_value'])) {
          $take_action_title = $value['field_take_action_text']['#items'][0]['safe_value'];
        }
        else {
          $take_action_title = "";
        }

        // Get the icon
        if (isset($value['field_take_action_icon']['#items'][0]['value'])) {
          $take_action_icon = $value['field_take_action_icon']['#items'][0]['value'];
        }
        else {
          $take_action_icon = "";
        }

        // Get the url
        if (isset($value['field_take_action_link']['#items'][0]['display_url'])) {
          $take_action_url = $value['field_take_action_link']['#items'][0]['display_url'];
        }
        else {
          $take_action_url = "";
        }

      ?>

      <div class="take-action-group-wrapper row-<?php print $rownum; ?> row-<?php print $row_type; ?> <?php print $take_action_icon; ?>-colors">
          <a class="take-action-group-link" href="<?php print $take_action_url; ?>">
            <div class="take-action-<?php print $take_action_icon; ?>-icon"></div>
            <div class="take-action-group-title">
              <?php print $take_action_title; ?>
            </div>
            <div class="take-action-chevron icon icon-chevron-right"></div>
          </a>
      </div>

    <?php endforeach; ?>
  <?php endif; ?>
<?php endforeach; ?>
</div>