<?php

// Plugin definition
$plugin = array(
    'padded_headline' => array(
        // Title and description of the plugin
        'title' => t('Padded Headline Pane'),
        'description' => t('Non-hero headline pane with padding for top panel region.'),
        // Define a theme function for this plugin
        'render pane' => 'padded_headline_style_render_pane',
        // We'll be using a template for rendering
        'hook theme' => array(
            'padded_headline_style' => array(
                'variables' => array('content' => NULL),
                'path' => drupal_get_path('module', 'sunrun_panels') . '/plugins/styles/padded_headline',
                'template' => 'padded-headline',
            ),
        ),
    ),
);

/**
 * Render callback.
 */
function theme_padded_headline_style_render_pane($vars) {

    $content = $vars['content'];
    $pane = $vars['pane'];
    $display = $vars['display'];

    if (empty($content->content)) {
        return;
    }

    $output = theme('panels_pane', array('content' => $content, 'pane' => $pane, 'display' => $display));

    // Just stick a box around the standard theme_panels_pane.
    $output = theme('padded_headline_style', array('content' => $output));
    return $output;
}
