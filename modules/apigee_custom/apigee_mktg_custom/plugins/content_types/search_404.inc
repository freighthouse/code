<?php

/**
 * @file
 * Plugin to handle the "Topic" list for about/api-best-practices.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('404 Search'),
  'single' => true,
  // 'icon' => 'icon_page.png',
  'description' => t('The search form for the 404 page.'),
  'category' => t('Apigee custom'),
  'defaults' => array(
    'title' => '',
    'button' => '',
    'description' => '',
  ),
);

/**
 * Output function for the 'type_list' content type.
 */
function apigee_mktg_custom_search_404_content_type_render($subtype, $conf, $panel_args) 
{
    $block = new stdClass();

    $block->content = drupal_get_form('search_form');
    $block->content['submit']['#value'] = $conf['button'];

    $block->content['keys']['#title'] = $conf['title'];
    $block->content['keys']['#description'] = '';

    $block->content['desc'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('clearfix'),
    ),
    );
    $block->content['desc']['text'] = array(
    '#markup' => $conf['description'],
    );
  
    unset($block->content['#attributes']['class'][1]);
    unset($block->content['#attributes']['class'][2]);
    unset($block->content['submit']['#attributes']['style']);

    return $block;
}

function apigee_mktg_custom_search_404_content_type_edit_form($form, &$form_state) 
{
    $conf = $form_state['conf'];

    $form['title'] = array(
    '#type' => 'textfield',
    '#default_value' => $conf['title'],
    '#title' => t('The title of the search form.'),
    );

    $form['button'] = array(
    '#type' => 'textfield',
    '#default_value' => $conf['button'],
    '#title' => t('The button text of the search form.'),
    );

    $form['description'] = array(
    '#type' => 'textarea',
    '#default_value' => $conf['description'],
    '#title' => t('The description of the search form.'),
    );

    return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function apigee_mktg_custom_search_404_content_type_edit_form_submit($form, &$form_state) 
{
    foreach (array_keys($form_state['plugin']['defaults']) as $key) {
        if (array_key_exists($key, $form_state['values'])) {
            $form_state['conf'][$key] = $form_state['values'][$key];
        }
    }
}
