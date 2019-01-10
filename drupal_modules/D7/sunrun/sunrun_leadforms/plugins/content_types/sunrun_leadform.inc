<?php
$plugin = array(
  'single' => TRUE,
  'title' => t('Sunrun Leadforms'),
  'description' => t('Build a form block'),
  'category' => t('Miscellaneous'),
  'edit form' => 'sunrun_leadforms_leadform',
  'render callback' => 'sunrun_leadforms_leadform_render',
  'admin info' => 'sunrun_leadforms_leadform_info',
  'defaults' => array(),
  'all contexts' => TRUE,
);

/**
 * Admin info.
 */
function sunrun_leadforms_leadform_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    // Render as block
    $theme = ucwords(str_replace("-", " ", $conf['theme']));
    $block = new stdClass;
    $block->title = '<strong>' . t('Theme:') . '</strong> ' . $theme;
    $block->content = '<strong>' . t('Redirect To:') . '</strong> ' . $conf['redirect'] . '<br/>';
    $block->content.= '<strong>' . t('Form Type:') . '</strong> ' . $theme;
    return $block;
  }
}

/**
 * Edit form
 */
function sunrun_leadforms_leadform($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['theme'] = array(
    '#type' => 'select',
    '#title' => t('Form Type'),
    '#description' => t('Choose one of the available forms.'),
    '#options' => array(
      'standard-leadform' => t('Standard Zeus Lead'),
      'standard-leadform-homepage' => t('Standard Lead (w/side Image)'),
      'standard-leadform-horizontal' => t('Standard Lead Form - Horizontal'),
      'referral-form' => t('Referral'),
      'purls' => t('PURLS'),
      'soft-signup' => t('Soft Signup'),
      'click-to-call' => t('Click to call'),
      'service-transfer-form' => t('Service Transfer Form'),
    ),
    '#default_value' => $conf['theme'],
  );
  $form['redirect'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirect URL'),
    '#description' => t('The url to redirect to after a successful Marketo submission.'),
    '#default_value' => $conf['redirect'],
  );
    $form['technology'] = array(
        '#type' => 'textfield',
        '#title' => t('Technology'),
        '#description' => t('The value of the technology field.'),
        '#default_value' => $conf['technology'],
    );
  return $form;
}

/**
 * Edit form submit function.
 */
function sunrun_leadforms_leadform_submit($form, &$form_state) {
  $form_state['conf']['redirect'] = $form_state['values']['redirect'];
  $form_state['conf']['theme']    = $form_state['values']['theme'];
  $form_state['conf']['technology'] = $form_state['values']['technology'];
}

/**
 * Render the panel.
 */
function sunrun_leadforms_leadform_render($subtype, $conf, $args, $contexts) {
  if ($contexts['panelizer']->empty) {
    return false;
  }
  return sunrun_leadforms_leadform_build($conf);
}

/**
 * Helper to build the Marketo leadform block
 */
function sunrun_leadforms_leadform_build($conf){
  // Render as a block.
  $block = new stdClass();
  $environment = variable_get('marketo_environment', '//app-ab02.marketo.com');
  $munchkin_id = variable_get('munchkin_id');
  $tcpa_disclosure = variable_get('tcpa_disclosure');
  $oot_msg = variable_get('oot_msg');

  drupal_add_js('https://www.sunruntransit.com/pageid.js?field_name=Web_User_ID__c&amp;ignore_vid=true&amp;auto_insert=false', array(
    'type' => 'external',
    'scope' => 'footer',
    'group' => JS_THEME,
    'defer' => TRUE,
  ));

  // Different variables by form
  switch ($conf['theme']) {
    case 'standard-leadform':
    case 'standard-leadform-homepage':
//      drupal_add_js(drupal_get_path('theme', 'sunrun') . '/public/assets/scripts/jquery.validate.methods.js');
      drupal_add_js(drupal_get_path('module', 'sunrun_leadforms') . '/assets/js/jquery.validate.min.js');
      drupal_add_js('sites/all/libraries/sunrunzipcode/sunrunzipcode.js');
      drupal_add_js(drupal_get_path('module', 'sunrun_leadforms') . '/assets/js/sunrun_zeus_forms.js');
      drupal_add_js(array(
        'sunrun_leadforms' => array(
          'form' => 'standard-leadform',
          'redirect' => $conf['redirect'],
        )
      ), 'setting');
      // Decide between themes
      if($conf['theme'] == 'standard-leadform'){
        $block->content = theme('standard-leadform', array(
          'redirect' => $conf['redirect'],
          'base_url' => $GLOBALS['base_url'],

        ));
      } else {
        $block->content = theme('standard-leadform-homepage', array(
          'headline' => variable_get('homepage_leadform_headline'),
          'blurb'    => variable_get('homepage_leadform_blurb'),
          'redirect' => $conf['redirect'],
        ));
      }
      break;

      case 'standard-leadform-horizontal':
          drupal_add_js('sites/all/libraries/sunrunzipcode/sunrunzipcode.js');
          drupal_add_js(drupal_get_path('module', 'sunrun_leadforms') . '/assets/js/jquery.validate.min.js');
          drupal_add_js(drupal_get_path('module', 'sunrun_leadforms') . '/assets/js/sunrun_zeus_forms.js');
          drupal_add_js(drupal_get_path('module', 'sunrun_leadforms') . '/assets/js/sunrun_horizontal_leadforms.js');
          drupal_add_js(array(
              'sunrun_leadforms' => array(
                  'form' => 'standard-leadform-horizontal',
                  'redirect' => $conf['redirect'],
              )
          ), 'setting');
          $block->content = theme('standard-leadform-horizontal', array(
              'headline' => variable_get('homepage_leadform_headline'),
              'blurb' => variable_get('homepage_leadform_blurb'),
              'redirect' => $conf['redirect'],
              'base_url' => $GLOBALS['base_url'],
              'technology' => (!empty($conf['technology'])) ? $conf['technology'] : '',
          ));
          break;
    
    case 'purls':
      // The session variable should be present
      if(isset($_SESSION['PURL']) && !empty($_SESSION['PURL'])){
        $user = $_SESSION['PURL'];
        $form_id = variable_get('purls_form_id');

        drupal_add_js(drupal_get_path('module', 'sunrun_leadforms') . '/assets/js/sunrun_purls.js');
        drupal_add_js(array(
          'sunrun_purls' => array(
            'form_id' => $form_id,
            'environment' => $environment,
            'munchkin_id' => $munchkin_id,
            'keycode' => $user->code,
            'first_name' => $user->first,
            'last_name' => $user->last,
            'address' => $user->address,
            'city' => $user->city,
            'state' => $user->state,
            'zip' => $user->zip,
            'bill' => $user->bill,
            'redirect' => $conf['redirect'],
            'tcpa_disclosure' => $tcpa_disclosure,
          )
        ), 'setting');
        $block->content = theme('purls-user-info', array(
          'user' => $user,
          'form_id' => $form_id,
          'environment' => $environment,
          'redirect' => $conf['redirect'],
        ));
      }
      break;

    case 'soft-signup':

      $form_id = variable_get('softsignup_form_id');
      drupal_add_js(drupal_get_path('module', 'sunrun_leadforms') . '/assets/js/sunrun_leadforms.js');
      drupal_add_js(array(
        'sunrun_leadforms' => array(
          'form' => 'soft-signup',
          'form_id' => $form_id,
          'environment' => $environment,
          'munchkin_id' => $munchkin_id,
          'redirect' => $conf['redirect'],
        )
      ), 'setting');

      $block->content = theme('soft-signup-form', array(
        'form_id' => $form_id,
        'environment' => $environment,
        'redirect' => $conf['redirect'],
      ));
    break;


      case 'service-transfer-form':
        // /renewsolar
        $form_id = 480;
        $environment = "//app-sjl.marketo.com";
        drupal_add_js(drupal_get_path('module', 'sunrun_leadforms') . '/assets/js/sunrun_leadforms.js');
        drupal_add_js(array(
          'sunrun_leadforms' => array(
            'form' => 'service-transfer-form',
            'form_id' => $form_id,
            'environment' => $environment,
            'munchkin_id' => "935-SWT-917",
            'redirect' => $conf['redirect'],
            'tcpa_disclosure' => $tcpa_disclosure,
          )
        ), 'setting');

        $block->content = theme('service-transfer-form', array(
          'form_id' => $form_id,
          'environment' => $environment,
          'redirect' => $conf['redirect'],
        ));
        break;

    case 'referral-form':
      $form_id = variable_get('referral_form_id', '1187');

      drupal_add_js(drupal_get_path('module', 'sunrun_leadforms') . '/assets/js/sunrun_leadforms.js');
      drupal_add_js(array(
        'sunrun_leadforms' => array(
          'form' => 'referral-form',
          'form_id' => $form_id,
          'environment' => $environment,
          'munchkin_id' => $munchkin_id,
          'redirect' => $conf['redirect'],
          'tcpa_disclosure' => $tcpa_disclosure,
        )
      ), 'setting');

      $block->content = theme('referral-form', array(
        'form_id' => $form_id,
        'environment' => $environment,
        'munchkin_id' => $munchkin_id,
        'redirect' => $conf['redirect'],
      ));
      break;
    case 'click-to-call':
      // only display the click to call block within business hours
      if(!_sunrun_leadforms_check_business_hours()) return;

      $block->content = theme('click-to-call-form');
      break;
      
    }
    return $block;
}
