<?php

if(drupal_get_path_alias($_GET['q']) == 'rating-lookup' && isset($_SESSION['PURL']))
{
    $address = $_SESSION['PURL']->address." ".$_SESSION['PURL']->city." ".$_SESSION['PURL']->state." ".$_SESSION['PURL']->zip;
    drupal_add_js(drupal_get_path('module', 'sunrun_leadforms') . '/assets/js/sunrun_roof_finder.js');
    drupal_add_js(array('sunrun_roof_finder' => array(
        'address' => $address,
    )), 'setting');
    if(ENVIRONMENT == 'local') { // allow testing of the calculator locally
      drupal_add_js('//maps.googleapis.com/maps/api/js?sensor=false', 'external');
    } else {
      drupal_add_js('//maps.googleapis.com/maps/api/js?sensor=false&client=gme-sunruninc1', 'external');
    }
}

?>

<div class="map-wrapper hidden-narrow-phone">
    <div class="map-overlay">
    </div>
    <div class="map-header">
        <div class="map-canvas"></div>
    </div>
    <h1 class="page-header"></h1>
</div>
