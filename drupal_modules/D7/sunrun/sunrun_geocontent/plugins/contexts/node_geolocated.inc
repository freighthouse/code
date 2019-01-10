<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  // Visible title.
  'title'             => t('Node (geolocated)'),
  // Description of context.
  'description'       => t('A node loaded based on geolocation.'),
  // Function to create context.
  'context'           => 'ctools_context_create_node_geolocated',
  // Keyword to use for %substitution.
  'keyword'           => 'node_geolocated',
  // The unique identifier for this context for use by required context checks.
  'context name'      => 'node_geolocated',
  // We use the same of node context
  'convert list' => 'ctools_context_node_convert_list',
  // We use the same of node context
  'convert' => 'ctools_context_node_convert',
);

/**
 * It's important to remember that $conf is optional here, because contexts
 * are not always created from the UI.
 */
function ctools_context_create_node_geolocated($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('node_geolocated');
  $context->plugin = 'node_geolocated';
  if ($empty) {
    return $context;
  }
  $node = sunrun_geocontent_load_node();
  // If there is a node
  if($node){
    $context->data     = $node;
    $context->title    = $node->title;
    $context->argument = $node->nid;
    $context->restrictions['type'] = array($node->type);
  }
  return $context;
}