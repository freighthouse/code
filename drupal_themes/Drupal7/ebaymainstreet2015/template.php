<?php

function ebaymainstreet2015_css_alter(&$css) {
  //dsm($css);
  unset($css[drupal_get_path('module','system').'/system.menus.css']);
  unset($css[drupal_get_path('module','system').'/system.theme.css']);
}

function ebaymainstreet2015_preprocess_html(&$vars) {
  //dsm($vars);

  // Add external web fonts
  drupal_add_css('https://fast.fonts.net/cssapi/8c6793d1-2870-42d6-8979-08b184b7b7b3.css', array('type' => 'external'));

  // Remove drupal hard coded no-sidebars class
  $vars['classes_array'][3] = '';

  // check for sidebar
  if (!empty($vars['page']['sidebar'])) {
    $vars['classes_array'][] = 'has-sidebar';
  }
  else {
    $vars['classes_array'][] = 'no-sidebar';
  }

  // No related news class display
  if (isset($vars['classes_array'][7]) && $vars['classes_array'][7] == 'node-type-issue') {
    if (isset($vars['page']['content']['views_news-block_7'])) {
      $vars['classes_array'][] = 'has-related-news';
    }
    else {
      $vars['classes_array'][] = 'no-related-news';
    }
  }

}

function ebaymainstreet2015_preprocess_page(&$vars) {
  // Adds page template suggestion based on node type.
  if (isset($vars['node'])) {
    $vars['theme_hook_suggestions'][] = 'page__'. $vars['node']->type;
  }

  // Override issue title
  if (isset($vars['node'])) {
    $node = $vars['node'];
    if (isset($node->type)) {
      if ($node->type == 'member') {
        $text = 'Featured Member';
        $vars['page']['content']['blockify_blockify-page-title']['#markup'] = '<h1 class="title" id="page-title">' . check_plain($text) . '</h1>';
      }
    }
  }
    // Template suggestions.
    // only do this for page-type nodes and only if Path module exists
    if (module_exists('path') && isset($vars['node']))
    {
        // look up the alias from the url_alias table
        $source = 'node/' .$vars['node']->nid;
        $alias = db_query("SELECT alias FROM {url_alias} WHERE source = '$source'");

        // store all the results in an array
        $all_results = $alias->fetchAll();

        // store the length of this array
        $results_length = count($all_results);

        // if an alias is found
        if ($alias != '')
        {

            for ($i=0; $i<$results_length; $i++) {

                // for each url alias found
                $each_alias = $all_results[$i]->alias;
                $current_path = request_path();

                // compare it to the current path. if they match
                if ($each_alias = $current_path) {

                    // build a suggestion for every possibility
                    $parts = explode('/', $each_alias);
                    $suggestion = '';
                    foreach ($parts as $part)
                    {
                        if ($suggestion == '')
                        {
                            // first suggestion gets prefaced with 'page__'
                            $suggestion .= "page__$part";
                        }
                        else
                        {
                            // subsequent suggestions get appended
                            $suggestion .= "__$part";
                        }
                        // convert hyphens to underscores.
                        $suggestion =  str_replace('-', '_', $suggestion);
                        // add the suggestion to the array
                        $vars['theme_hook_suggestions'][] = $suggestion;
                    }
                }
            }
        }
    }

}

function ebaymainstreet2015_preprocess_image(&$variables) {
  // Do not allow drupal to set width and height on images
  unset($variables['width'], $variables['height'], $variables['attributes']['width'], $variables['attributes']['height']);
}

// function ebaymainstreet2015_preprocess_node(&$vars) {
//   //dsm($vars);
// }

// function ebaymainstreet2015_preprocess_region(&$vars) {
//   //dsm($vars);
// }

// function ebaymainstreet2015_preprocess_block(&$vars) {
//   //dsm($vars);
// }

// Add span with visuallyhidden class to a specific menu (for social media icons)
function ebaymainstreet2015_menu_link(array $variables) {
  $element = $variables ['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  if ($element['#original_link']['menu_name'] == 'menu-ems2015---header-social-lin') {
    $linkText = '<span class="visuallyhidden">' . $element['#title'] . '</span>';
    $element['#localized_options']['html'] = true;
  } else {
    $linkText = $element['#title'];
    $linkText = '<span>' . $element['#title'] . '</span>';
  }

  $plainTitle = drupal_html_class($element['#title']);
  $element['#attributes']['class'][] = 'menu-' . strtolower($plainTitle);
  $options = $element['#localized_options'];
  $options['html'] = 'TRUE';

  $output = l($linkText, $element['#href'], $options);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function ebaymainstreet2015_form_alter(&$form, &$form_state, $form_id)
{
  if($form_id == 'contact_site_form') {
    $form['actions']['submit']['#submit'][] = 'ebaymainstreet2015_redirect_handler';
  }
}

function ebaymainstreet2015_redirect_handler($form, &$form_state)
{
  unset($_REQUEST['destination']); // this doesn't seem to work though
  unset($form['#redirect']); // i think this doesnt do anything because $form is not a reference
  $form_state['redirect'] = url('contact/thank-you');
}