<?php foreach ($items as $delta => $item): ?>
  <?php if (isset($item['entity'])): ?>

    <?php $counter = count($items) - 1; ?>
    <?php foreach ($item['entity']['field_collection_item'] as $key => $value): ?>
      <?php
        $rownum = $delta + 1;
        if ($rownum % 2 == 0) {
          $row_type = 'even';
        }
        else {
          $row_type = 'odd';
        }

        // Get the dates
        if (isset($value['field_timeline_date']['#items'][0]['value'])) {
          $date_unformatted = $value['field_timeline_date']['#items'][0]['value'];
          // Format the date to be used as data by the plugin
          $date_data_format = date('Y,m,d', strtotime($date_unformatted)); // 15/08/2012
          // Format the date for display
          $date_readable_format = date('F j, Y', strtotime($date_unformatted)); // August 15, 2012
        }
        else {
          $date_data_format = '';
          $date_readable_format = '';
        }

         // Get the long_description
        if (isset($value['field_timeline_long_description']['#items'][0]['safe_value'])) {
          $description = trim($value['field_timeline_long_description']['#items'][0]['safe_value']);
          $description = preg_replace('~>\s+<~', '><', $description);
          $description = str_replace('"', '&quot;', $description);
          $description = json_encode($description);
        }
        else {
          $description = '""';
        }

        // Get the title
        if (isset($value['field_timeline_title']['#items'][0]['safe_value'])) {
          $title = $value['field_timeline_title']['#items'][0]['safe_value'];
        }
        else {
          $title = '';
        }
        $output = '';
        if ($counter != $delta) {
          $output = '{"startDate":"' . $date_data_format . '","headline":"' . $date_readable_format . '","text":' . $description . '},';
        }
        else {
          $output = '{"startDate":"' . $date_data_format . '","headline":"' . $date_readable_format . '","text":' . $description . '}';
        }
      ?>
      <?php print trim($output); ?>
    <?php endforeach; ?>
  <?php endif; ?>
<?php endforeach; ?>