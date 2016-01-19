<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_preprocess_html().
 */
function iha_preprocess_html(&$vars) {
  //Fonts
  drupal_add_css('https://fonts.googleapis.com/css?family=Lato:400,700,300',array('type' => 'external'));

  if ($node = menu_get_object()) {
    $node_wrapper = entity_metadata_wrapper('node', $node);

    //If the content type of this node has a field, field_body_classes_select,
    //let's pass the value(s) of the field to the body class in html.tpl.php
    if (isset($node_wrapper->field_body_classes_select)){
      $body_classes = $node_wrapper->field_body_classes_select->value();
      foreach ($body_classes as $body_class) {
      $vars['classes_array'][] = $body_class;
      }
    }

    //If the content type of this node has a field, field_custom_body_classes,
    //let's pass the value(s) of the field to the body class in html.tpl.php
    if (isset($node_wrapper->field_custom_body_classes)){
      $custom_body_classes = $node_wrapper->field_custom_body_classes->value();
      foreach ($custom_body_classes as $custom_body_class) {
      $vars['classes_array'][] = $custom_body_class;
      }
    }
  }
}

/* User login customizations by Jcerda for Project6
 *
 *  Remove labels and add HTML5 placeholder attribute to login form
 */
function iha_form_alter(&$form, &$form_state, $form_id) {
  if ( TRUE === in_array( $form_id, array( 'user_login', 'user_login_block') ) )
    $form['name']['#attributes']['placeholder'] = t( 'Username' );
    $form['pass']['#attributes']['placeholder'] = t( 'Password' );
    $form['name']['#title_display'] = "invisible";
    $form['pass']['#title_display'] = "invisible";
}

/*
 *  Remove login form descriptions
 */
function iha_form_user_login_alter(&$form, &$form_state) {
    $form['name']['#description'] = t('');
    $form['pass']['#description'] = t('');
}

/*
 *  Search box
 */

function iha_preprocess_page(&$variables){
  $search_box = drupal_render(drupal_get_form('search_form'));
  $variables['search_box'] = $search_box;
  if (drupal_is_front_page()) {
        unset($variables['page']['content']['system_main']['default_message']); //will remove message "no front page content is created"
        drupal_set_title(''); //removes welcome message (page title)
    }
  if (arg(0) == 'node') {
    $variables['node_content'] =& $variables['page']['content']['system_main']['nodes'][arg(1)];
  }

  if (isset($variables['node']->type)) {
    $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
  }

  // Prepare the mobile menu.
  $user_menu = menu_tree('user-menu');
  $main_menu = menu_tree('main-menu');
  $menu_tree = array_merge($main_menu, $user_menu);
  // FYI for future dev's - If need to add more menu items, then load the other menu through menu tree as well and do a
  // array merge or for loop to attach the items to the $menu_tree.

  $mobile_menu = '<ul class="list-unstyled main-menu">';

  foreach($menu_tree as $mlid => $mm) {
    if (is_int($mlid)) {
        $mobile_menu .= iha_render_mobile_menu($mm);
    }
  }

  $mobile_menu .= '</ul>';
  $variables['mobile_menu'] = $mobile_menu;
}


/*
 *  Menus
 */

/**
 * Overrides theme_menu_link().
 */
function iha_menu_link__menu_block($variables) {
  return theme_menu_link($variables);
}

/**
 * Helper function to render a clean mobile menu without Bootstrap's overrides.
 *
 * @param $element Should contain the link and the below items.
 * @return string
 */
function iha_render_mobile_menu($element, $class = '') {
    $sub_menu = '';

    if ($element['#below']) {
        $sub_menu = '<ul class="list-unstyled">';
        foreach ($element['#below'] as $mlid => $link) {
            if (is_int($mlid)) {
                $sub_menu .= iha_render_mobile_menu($link, 'sub-nav');
            }
        }
        $sub_menu .= '</ul>';
        $output = '<a href="' . url($element['#href']) . '">' . $element['#title'] . '</a> <a href="#"><i class="glyphicon glyphicon-menu-right pull-right"></i></a>';
    }
    else {
        $output = '<a href="' . url($element['#href']) . '">' . $element['#title'] . ' <span class="icon"></span></a>';
    }

    return '<li class="'. $class . '">' . $output . $sub_menu . "</li>\n";
}
