<?php

// Plugin definition
$plugin = array(
    'gray_bg' => array(
        // Title and description of the plugin
        'title' => t('Gray Background Pane'),
        'description' => t('Gray background pane with padding.'),
        // Define a theme function for this plugin
        'render pane' => 'gray_bg_style_render_pane',
        // We'll be using a template for rendering
        'hook theme' => array(
            'gray_bg_style' => array(
                'variables' => array('content' => NULL),
                'path' => drupal_get_path('module', 'sunrun_panels') . '/plugins/styles/gray_bg',
                'template' => 'gray-bg',
            ),
        ),
    ),
);

/**
 * Render callback.
 */
function theme_gray_bg_style_render_pane($vars) {

    $content = $vars['content'];
    $pane = $vars['pane'];
    $display = $vars['display'];

    if (empty($content->content)) {
        return;
    }

    $output = theme('panels_pane', array('content' => $content, 'pane' => $pane, 'display' => $display));

    // Just stick a box around the standard theme_panels_pane.
    $output = theme('gray_bg_style', array('content' => $output));
    return $output;
}
