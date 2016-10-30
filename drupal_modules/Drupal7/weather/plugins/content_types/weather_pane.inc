<?php

$plugin = array(
  'title' => t('User Timestamp'),
  'description' => t('Displays a read more link.'),
  'single' => true,
  'content_types' => array('weather_pane'),
  'render callback' => 'weather_render',
  'admin info' => 'weather_pane_admin_info',
  'edit form' => 'weather_pane_edit_form',
  'category' => array(t('Weather Test'), -9),
);

/**
 * Callback for panel pane.
 *
 * @param $subtype
 * @param $conf
 * @param $context
 */
function weather_pane_admin_info($subtype, $conf, $contexts)
{
    if (!empty($conf)) {
        global $user;
        $date = weather_report_callback();

        $block = new stdClass;
        $block->title = $conf['title'];
        $block->content = array(
        '#markup' => variable_get('weather_message') . '<br /><br />' . $date,
          '#attached' => array(
            'js' => drupal_add_js(drupal_get_path('module', 'weather') . '../../js/weather.js'),
          ),
        );
        return $block;
    }
}

/**
 * Ctools weather pane edit form.
 *
 * @param  $form
 * @param  $form_state
 * @return mixed
 */
function weather_pane_edit_form($form, &$form_state)
{
    $conf = $form_state['conf'];
    $form['weather_pane'] = array(
    '#type' => 'fieldset',
    '#title' => t('Block Message Settings'),
    );

    $form['weather_pane']['Message']['weather_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Block message'),
    '#description' => t('Customize your message here.'),
    '#default_value' => !empty($conf['weather_pane']) ? $conf['weather_pane'] : variable_get('weather_message'),
    );
    return $form;
}

/**
 * Ctools edit form submit handler.
 *
 * @param $form
 * @param $form_state
 */
function weather_submit($form, &$form_state)
{
    foreach (array('weather_pane') as $key) {
        $form_state['conf'][$key] = $form_state['values'][$key];
    }
}

/**
 * Render callback function.
 *
 * @param  $subtype
 * @param  $conf
 * @param  $args
 * @param  $context
 * @return stdClass
 */
function weather_render($subtype, $conf, $panel_args, $context)
{
    global $user;
    $date = weather_report_callback();

    $block = new stdClass();
    $block->title = $conf['weather_pane'];
    $block->content = array(
    '#markup' => $conf['weather_message'] . '<br>' . $date,
    '#attached' => array(
      'js' => array(
        drupal_add_js(drupal_get_path('module', 'weather') . '../../js/weather.js'),
      ),
    ),
    );
    return $block;
}
