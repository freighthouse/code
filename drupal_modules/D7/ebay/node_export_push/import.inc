<?php

/**
 * Process POST data and delegate the import to node_export.
 */
function node_export_push_import() {
  
  // Process an import if we've been given one
  if (isset($_POST['export'])) {
    $node_code = $_POST['export'];
    
    // We need to decode the import because node_export doesn't give us a validation hook
    // to reject individual imports.
    $import = node_export_node_decode($node_code);
    if (is_array($import)) {
      node_export_import($node_code, NULL, FALSE);
      // Perform a redirect back to the same page so that hitting refresh doesn't resubmit the nodes
      // Emulates Drupal's form submit PRG pattern
      drupal_goto(POSTBOX_PATH);
    } else {
      node_export_post_single_import($import, NULL, TRUE);
    }
  } 
}
