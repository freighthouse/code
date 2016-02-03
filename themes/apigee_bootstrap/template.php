<?php

/**
 * Preprocessor for theme('node')
 *
 * @see node.tpl.php
 */
function apigee_bootstrap_preprocess_node(&$variables) 
{

}

/**
 * Preprocessor for theme('html')
 *
 * @see html.tpl.php
 */
function apigee_bootstrap_preprocess_html(&$vars) 
{
    // Add some additional body classes based on path
    $path = drupal_get_path_alias($_GET['q']);
    $aliases = explode('/', $path);
    foreach($aliases as $alias) {
        $vars['classes_array'][] = drupal_clean_css_identifier($alias);
    }
}

function apigee_bootstrap_preprocess_page(&$vars) 
{
    if (isset($vars['node']->type)) {
        $vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
    }

    {
    $search_box = drupal_render(drupal_get_form('search_form'));
    $vars['search_box'] = $search_box;}
}

function apigee_bootstrap_form_alter( &$form, &$form_state, $form_id ) 
{
    if (in_array($form_id, array( 'search_form'))) {
        // Adding placeholders to fields
        $form['basic']['keys']['#attributes']['placeholder'] = t('Search text here...');
        // Prevent user from searching the default text
        $form['#attributes']['onsubmit'] = "if(this.search_block_form.value=='Search'){ alert('Please enter a search'); return false; }";
        // $form['#title'] = t('Search here'); // Change the text on the label element
        // $form['#title_display'] = 'invisible'; // Toggle label visibilty
        // $form['#size'] = 100;  // define size of the textfiel
    }
}

/**
 * Helper function to find and render a block by Jeremy Cerda @FreighthouseNYC
 * PS. - Necessary to support i18n
 */
function render_block_content($module, $delta) 
{
    $output = '';
    if ($block = block_load($module, $delta)) {
        if ($build = module_invoke($module, 'block_view', $delta)) {
            $delta = str_replace('-', '_', $delta);
            drupal_alter(array('block_view', "block_view_{$module}_{$delta}"), $build, $block);

            if (!empty($build['content'])) {
                return is_array($build['content']) ? render($build['content']) : $build['content'];
            }
        }
    }
    return $output;
}