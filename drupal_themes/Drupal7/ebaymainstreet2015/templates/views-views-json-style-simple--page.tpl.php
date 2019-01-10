<?php
/**
 * @file views-views-json-style-simple.tpl.php
 * Default template for the Views JSON style plugin using the simple format
 *
 * Variables:
 * - $view: The View object.
 * - $rows: Hierachial array of key=>value pairs to convert to JSON
 * - $options: Array of options for this style
 *
 * @ingroup views_templates
 */

$jsonp_prefix = $options['jsonp_prefix'];

if ($view->override_path) {
  // We're inside a live preview where the JSON is pretty-printed.
  $json = _views_json_encode_formatted($rows, $options);
  if ($jsonp_prefix) $json = "$jsonp_prefix($json)";
  print "<code>$json</code>";
}
else {
  $json = _views_json_json_encode($rows, $bitmask);
  if ($options['remove_newlines']) {
     $json = preg_replace(array('/\\\\n/'), '', $json);
  }

  if (isset($_GET[$jsonp_prefix]) && $jsonp_prefix) {
    $json = check_plain($_GET[$jsonp_prefix]) . '(' . $json . ')';
  }

  if ($options['using_views_api_mode']) {
    // We're in Views API mode.
    print $json;
  }
  else {

    // Get the start date
    if (isset($view->result[0]->field_field_timeline_start_date[0]['raw']['value'])) {
      $date_data_format = date('Y,m,d', strtotime($view->result[0]->field_field_timeline_start_date[0]['raw']['value']));
    }
    else {
      $date_data_format = '';
    }

    // Get the summary
    if (isset($view->result[0]->field_field_timeline_summary[0]['rendered']['#markup'])) {
      $timeline_summary = trim($view->result[0]->field_field_timeline_summary[0]['rendered']['#markup']);
      $timeline_summary = preg_replace('~>\s+<~', '><', $timeline_summary);
      $timeline_summary = str_replace('"', '&quot;', $timeline_summary);
      $timeline_summary = json_encode($timeline_summary);
    }
    else {
      $timeline_summary = '""';
    }

    // Initialize the json container
    $json_timeline_node_data = '';

    // Add our json prefix
    $json_timeline_node_data .= 'storyjs_jsonp_data = {"timeline":{"headline":"' . $view->result[0]->node_title . '","type":"default","text":' . $timeline_summary . ',"startDate":"' . $date_data_format . '","date": [';

    // Add our json node content
    if ($view->result[0]->field_field_timeline_item[0]['rendered']) {
      $json_timeline_node_data .= trim($view->result[0]->field_field_timeline_item[0]['rendered']);
    }

    // Add our json suffix
    $json_timeline_node_data .= ']}}';
    $json_output = preg_replace('/\s(?=([^"]*"[^"]*")*[^"]*$)/', '', $json_timeline_node_data);

    // We want to send the JSON as a server response so switch the content
    // type and stop further processing of the page.
    // $content_type = ($options['content_type'] == 'default') ? 'application/json' : $options['content_type'];
    $content_type = ($options['content_type'] == 'default') ? 'application/javascript' : $options['content_type'];
    drupal_add_http_header("Content-Type", "$content_type; charset=utf-8");
    print $json_output;
    drupal_page_footer();
    exit;
  }
}
