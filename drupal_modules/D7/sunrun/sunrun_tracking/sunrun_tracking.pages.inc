<?php
/**
 *	@file
 * 	Sunrun Tracking pages.
 */

/**
 * Callback/Ajax Handler for tracking
 */
function sunrun_tracking_track() {

    $tracking = _sunrun_tracking_track_init();

    // Retrieve JSON input string
    $received_json = file_get_contents("php://input");
    $json = drupal_json_decode($received_json);

    if(_sunrun_tracking_track_validate($json)) {
        // parse the query string into an array with key/values and merge
        // with the $json array
        parse_str(ltrim($json['query_string'], "?"), $parse);
        $json += $parse;

        $json['http_host'] = $_SERVER['HTTP_HOST'];

        // get current nodeid node
        if(isset($json['nodeid']) && $json['nodeid'] > 0) {
          $node = node_load($json['nodeid']);
        }

        $custom_channel = (isset($node->metatags['en']['channel']['value'])) ? $node->metatags['en']['channel']['value'] : NULL;
        $custom_lead_source = (isset($node->metatags['en']['lead_source']['value'])) ? $node->metatags['en']['lead_source']['value'] : NULL;

        // Track user
        $tracking->init($json, $custom_lead_source, $custom_channel);

        $payload['status'] = 'success';

        echo drupal_json_encode(array('payload' => $payload));
    }

    drupal_exit();
}

/**
 * Initializes the SunRunTracking object and returns it.  If a Static object
 * has previously been created, it gets returned.
 *
 * @return null|\SunRunTracking
 */
function _sunrun_tracking_track_init() {
    $tracking = &drupal_static(__FUNCTION__);

    // Confirm library exists
    if( ! isset($tracking) || empty($tracking)) {
        $lib_path = DRUPAL_ROOT . '/sites/all/libraries/tracking/tracking.php';

        if (!class_exists('SunRunTracking') && !include($lib_path)) {
            $message = t('Failed to find the SunRun tracking library.');
            watchdog('sunrun_tracking', $message, array(), WATCHDOG_ALERT);

            return NULL;
        }

        $tracking = new SunRunTracking();
    }

    return $tracking;
}

/**
 * Provide high level validation on the variables passed in during the JSON request.
 *
 * @param $track_vars Array of variables passed in as part of the JSON request
 * @return boolean true if valid, false otherwise
 */
function _sunrun_tracking_track_validate($track_vars) {
    if ($_SERVER['REQUEST_METHOD'] != 'POST') {
        header('HTTP/1.1 405 Not Post');
        return false;
    }

    return true;
}
