<?php
// @author: Jeremy Cerda
// @version: $Id: mncoremetrics.admin.inc 2844 2011-10-27 15:50:22Z jcerda $

module_load_include('inc', 'mncoremetrics', 'mncoremetrics.util');

function mncoremetrics_admin_main_form(&$form_state) 
{

    $open = (variable_get('mncoremetrics_setup_cfg', 0) ? 1 : 0);

    $form = array();

    $form['config_load'] = array(
    '#type'  => "checkbox",
    '#title' => t('Load from Config'),
    '#default_value' => variable_get('mncoremetrics_setup_cfg', 0),
    '#attributes' => array(
    'onclick' => 'mncoremetrics_admin_config_load_click()'
    )
    );

    // Advanced Settings
    $form['advanced_settings'] = array(
    '#type' => 'fieldset',
    '#collapsible' => true,
    '#collapsed' => $open,
    '#title' => t('Advanced Settings'),
    );
    $form['advanced_settings']['src'] = array(
    '#type' => 'textfield',
    '#title' => t('Coremetrics Source'),
    '#default_value' => variable_get('mncoremetrics_src', ''),
    '#description' => "Coremetrics source location.",
    '#size' => 30
    );
    $form['advanced_settings']['clientid'] = array(
    '#type' => 'textfield',
    '#title' => t('ClientID'),
    '#default_value' => variable_get('mncoremetrics_clientid', ''),
    '#description' => "Coremetrics ClientID.",
    '#size' => 8,
    '#maxlength' => 8
    );
    $form['advanced_settings']['clientid.test'] = array(
    '#value' => "<div><label style='font-weight:bold'>Test ID</label><p>".
    variable_get('mncoremetrics_clientid.test', '').
    "</p></div>",
    );
    $form['advanced_settings']['testing'] = array(
    '#type' => 'checkbox',
    '#title' => 'Testing Mode',
    '#default_value' => variable_get('mncoremetrics_testing', 1),
    '#description' => 'In testing mode, all data will be sent to the '.
    'test domain rather than the production server.',
    );

    // Domains
    $form['advanced_settings']['domains'] = array(
    '#type' => 'fieldset',
    '#collapsible' => true,
    '#collapsed' => $open,
    '#title' => t('Domains'),
    );
    $form['advanced_settings']['domains']['test'] = array(
    '#type' => 'textfield',
    '#title' => t('Testing'),
    '#default_value' => variable_get('mncoremetrics_domains.test', ''),
    '#description' => "Testing domain for data.",
    '#size' => 30
    );
    $form['advanced_settings']['domains']['prod'] = array(
    '#type' => 'textfield',
    '#title' => t('Production'),
    '#default_value' => variable_get('mncoremetrics_domains.prod', ''),
    '#description' => "Production domain for data",
    '#size' => 30
    );
    $form['advanced_settings']['domains']['cookie'] = array(
    '#type' => 'textfield',
    '#title' => t('Cookie'),
    '#default_value' => variable_get('mncoremetrics_domains.cookie', ''),
    '#description' => "Domain for site cookies.",
    '#size' => 30
    );


    $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save')
    );

    return $form;
}

function mncoremetrics_admin_main_form_submit($form, &$form_state) 
{
    if ($form_state['values']['config_load']) {
        watchdog("mncoremetrics", "Reloaded settings from cfg file.");
        variable_set('mncoremetrics_setup_cfg', 1);
        variable_set('mncoremetrics_setup', 1);
        mncoremetrics_load_cfg();
    } else {
        watchdog("mncoremetrics", "Settings changed from form.");
        variable_set('mncoremetrics_setup_cfg', 0);
        variable_set('mncoremetrics_src', $form_state['values']['src']);
        variable_set(
            'mncoremetrics_clientid',
            $form_state['values']['clientid']
        );
        variable_set(
            'mncoremetrics_clientid.test',
            "6".substr($form_state['values']['clientid'], 1)
        );

        variable_set(
            'mncoremetrics_domains.test',
            $form_state['values']['test']
        );
        variable_set(
            'mncoremetrics_domains.prod',
            $form_state['values']['prod']
        );
        variable_set(
            'mncoremetrics_domains.cookie',
            $form_state['values']['cookie']
        );

        variable_set(
            'mncoremetrics_testing',
            $form_state['values']['testing']
        );

        variable_set('mncoremetrics_setup', 1);
    }
}

function mncoremetrics_admin_main() 
{


    $ret = drupal_get_form('mncoremetrics_admin_main_form');

    $p = drupal_get_path('module', 'mncoremetrics').
    '/js/mncoremetrics.admin.js';
    drupal_add_js($p, 'module', 'header', false, false, false);

    return $ret;
}
