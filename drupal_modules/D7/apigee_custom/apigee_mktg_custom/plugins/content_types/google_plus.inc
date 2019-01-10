<?php

/**
 * @file
 * Plugin to create the "Google Plus" block.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Google Plus'),
  'single' => true,
  // 'icon' => 'icon_page.png',
  'description' => t('A block of recent posts on Google Plus.'),
  'category' => t('Apigee custom'),
  // 'render last' => TRUE,
  'defaults' => array(
    'api_key' => 'AIzaSyCUGdsNsNIcZnRU3L8njKIIUyilkuW4gXU',
    'user_id' => '115644647110011546248',
    'max_results' => 5,
    'cache_time' => 30,
    'participate_link' => '',
  ),
);

/**
 * Output function for the 'type_list' content type.
 */
function apigee_mktg_custom_google_plus_content_type_render($subtype, $conf, $panel_args) 
{

    $cache_key = 'apigee_mktg_custom_google_plus:' . implode(':', $conf);

    $cache = cache_get($cache_key);
    $max_lifetime = $conf['cache_time'] * 60;

    if (!$cache || (REQUEST_TIME - $cache->created > $max_lifetime)) {

        $options = array(
        'query' => array(
        'key' => $conf['api_key'],
        'maxResults' => $conf['max_results'],
        ),
        'external' => true,
        );

        $url = 'https://www.googleapis.com/plus/v1/people/' . $conf['user_id'] . '/activities/public';
        $url = url($url, $options);

        $headers = array();

        // Our cache might be old, but we still have eTags we can use.
        if ($cache && !empty($cache->data->headers['etag'])) {
            $headers['If-None-Match'] = $cache->data->headers['etag'];
        }

        $response = drupal_http_request($url, array('headers' => $headers));

        // New data;
        if ($response->code == 200) {
            $data = json_decode($response->data);

            $list = array();

            foreach ($data->items as $item) {
                $content = $item->title;
        
                $time_ago = format_interval((REQUEST_TIME - strtotime($item->published)), 1);

                $content .= '<br>' . l(t('Read more<span class="white-arrow"></span>'), $item->url, array('html' => true));

                $content .= '<div class="google-plus-time">'; 
                $content .= "<em>about $time_ago ago</em>";
                $content .= '</div>';
        
                $list[] = $content;
            }

            $variables = array(
            'items' => $list,
            'title' => '',
            'type' => 'ul',
            'attributes' => array('class' => array('google-plus-list')),
            );

            $block = new stdClass();

            $block->headers = $response->headers;

            $block->content = theme_item_list($variables);

            $options = array(
            'attributes' => array(
            'class' => array(
            'google-plus-participate',
            ),
            ),
            'html' => true,
            );

            $block->content .= l('Participate<span class="white-arrow"></span>', $conf['participate_link'], $options);

            $block->title = t('Google Plus');

            cache_set($cache_key, $block);
        }
        // Not modified, use cache.
        else if ($response->code == 304) {
            $block = $cache->data;
        }
        // Something went wrong!
        else {
            // If we have a cache, use that.
            if ($cache) {
                $block = $cache->data;
            }
            // Well shit.
            else {
                $block = new stdClass();
                $block->title = t('Google Plus');
                $block->content = '';
            }
        }
    }
    // Our cached copy is good.
    else {
        $block = $cache->data;
    }

    return $block;
}

function apigee_mktg_custom_google_plus_content_type_edit_form($form, &$form_state) 
{
    $conf = $form_state['conf'];

    $form['api_key'] = array(
    '#type' => 'textfield',
    '#default_value' => $conf['api_key'],
    '#title' => t('API key'),
    '#description' => t('The Google api key to use for these requests.'),
    );

    $form['user_id'] = array(
    '#type' => 'textfield',
    '#default_value' => $conf['user_id'],
    '#title' => t('User id'),
    '#description' => t('The Google + user id.'),
    );

    $form['max_results'] = array(
    '#type' => 'textfield',
    '#default_value' => $conf['max_results'],
    '#title' => t('Max results'),
    '#description' => t('Get this many, or fewer, results.'),
    );

    $form['cache_time'] = array(
    '#type' => 'textfield',
    '#default_value' => $conf['cache_time'],
    '#title' => t('Cache time'),
    '#description' => t('The number of minutes to cache the results.'),
    );

    $form['participate_link'] = array(
    '#type' => 'textfield',
    '#default_value' => $conf['participate_link'],
    '#title' => t('Participate link'),
    );

    return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function apigee_mktg_custom_google_plus_content_type_edit_form_submit($form, &$form_state) 
{
    foreach (array_keys($form_state['plugin']['defaults']) as $key) {
        if (array_key_exists($key, $form_state['values'])) {
            $form_state['conf'][$key] = $form_state['values'][$key];
        }
    }
}
