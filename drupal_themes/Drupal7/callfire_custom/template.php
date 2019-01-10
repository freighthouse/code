<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * A QUICK OVERVIEW OF DRUPAL THEMING
 *
 *   The default HTML for all of Drupal's markup is specified by its modules.
 *   For example, the comment.module provides the default HTML markup and CSS
 *   styling that is wrapped around each comment. Fortunately, each piece of
 *   markup can optionally be overridden by the theme.
 *
 *   Drupal deals with each chunk of content using a "theme hook". The raw
 *   content is placed in PHP variables and passed through the theme hook, which
 *   can either be a template file (which you should already be familiary with)
 *   or a theme function. For example, the "comment" theme hook is implemented
 *   with a comment.tpl.php template file, but the "breadcrumb" theme hooks is
 *   implemented with a theme_breadcrumb() theme function. Regardless if the
 *   theme hook uses a template file or theme function, the template or function
 *   does the same kind of work; it takes the PHP variables passed to it and
 *   wraps the raw content with the desired HTML markup.
 *
 *   Most theme hooks are implemented with template files. Theme hooks that use
 *   theme functions do so for performance reasons - theme_field() is faster
 *   than a field.tpl.php - or for legacy reasons - theme_breadcrumb() has "been
 *   that way forever."
 *
 *   The variables used by theme functions or template files come from a handful
 *   of sources:
 *   - the contents of other theme hooks that have already been rendered into
 *     HTML. For example, the HTML from theme_breadcrumb() is put into the
 *     $breadcrumb variable of the page.tpl.php template file.
 *   - raw data provided directly by a module (often pulled from a database)
 *   - a "render element" provided directly by a module. A render element is a
 *     nested PHP array which contains both content and meta data with hints on
 *     how the content should be rendered. If a variable in a template file is a
 *     render element, it needs to be rendered with the render() function and
 *     then printed using:
 *       <?php print render($variable); ?>
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. With this file you can do three things:
 *   - Modify any theme hooks variables or add your own variables, using
 *     preprocess or process functions.
 *   - Override any theme function. That is, replace a module's default theme
 *     function with one you write.
 *   - Call hook_*_alter() functions which allow you to alter various parts of
 *     Drupal's internals, including the render elements in forms. The most
 *     useful of which include hook_form_alter(), hook_form_FORM_ID_alter(),
 *     and hook_page_alter(). See api.drupal.org for more information about
 *     _alter functions.
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   If a theme hook uses a theme function, Drupal will use the default theme
 *   function unless your theme overrides it. To override a theme function, you
 *   have to first find the theme function that generates the output. (The
 *   api.drupal.org website is a good place to find which file contains which
 *   function.) Then you can copy the original function in its entirety and
 *   paste it in this template.php file, changing the prefix from theme_ to
 *   callfire_custom_. For example:
 *
 *     original, found in modules/field/field.module: theme_field()
 *     theme override, found in template.php: callfire_custom_field()
 *
 *   where callfire_custom is the name of your sub-theme. For example, the
 *   zen_classic theme would define a zen_classic_field() function.
 *
 *   Note that base themes can also override theme functions. And those
 *   overrides will be used by sub-themes unless the sub-theme chooses to
 *   override again.
 *
 *   Zen core only overrides one theme function. If you wish to override it, you
 *   should first look at how Zen core implements this function:
 *     theme_breadcrumbs()      in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called theme hook suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node--forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions and theme hook suggestions,
 *   please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/node/223440 and http://drupal.org/node/1089656
 */


/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
/* -- Delete this line if you want to use this function
function callfire_custom_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  callfire_custom_preprocess_html($variables, $hook);
  callfire_custom_preprocess_page($variables, $hook);
}
// */

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
/* -- Delete this line if you want to use this function
function callfire_custom_preprocess_html(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // The body tag's classes are controlled by the $classes_array variable. To
  // remove a class from $classes_array, use array_diff().
  //$variables['classes_array'] = array_diff($variables['classes_array'], array('class-to-remove'));
}
// */

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
/* -- Delete this line if you want to use this function
function callfire_custom_preprocess_page(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
/* -- Delete this line if you want to use this function
function callfire_custom_preprocess_node(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // Optionally, run node-type-specific preprocess functions, like
  // callfire_custom_preprocess_node_page() or callfire_custom_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}
// */

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function callfire_custom_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the region templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
/* -- Delete this line if you want to use this function
function callfire_custom_preprocess_region(&$variables, $hook) {
  // Don't use Zen's region--sidebar.tpl.php template for sidebars.
  //if (strpos($variables['region'], 'sidebar_') === 0) {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('region__sidebar'));
  //}
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function callfire_custom_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  // $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  //if ($variables['block_html_id'] == 'block-system-main') {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('block__no_wrapper'));
  //}
}
// */

/**
  * Display All Accessible Variables
  print '<pre>';
    var_dump(get_defined_vars());
  print '</pre>';
  <?php kpr(get_defined_vars()); ?>
 */

/**
 * Insert the ability to define a page.tpl.php based on node-types
 * Pre-process for page.tpl.php
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */

function callfire_custom_preprocess_page(&$variables, $hook) {
	if (!empty($variables['node'])) {
		$variables['theme_hook_suggestions'][] = 'page__node_' . $variables['node']->type;
  }
  if(arg(1) == 187001) {
    $variables['theme_hook_suggestions'][] =  'page__help';
  }
  if(arg(1) == 191001) {
    $variables['theme_hook_suggestions'][] =  'page__404_error';
  }

}

/**
 * Preprocess variables for node.tpl.php
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 */

function callfire_custom_preprocess_node(&$variables) {
	if (variable_get('node_submitted_' . $variables['node']->type, TRUE)) {
    $user_fields = user_load($variables['node']->uid);
    $firstname = field_get_items('user', $user_fields, 'field_firstname');
    $lastname = field_get_items('user', $user_fields, 'field_lastname');

    if($firstname) {
      if($lastname) {
        $user_name = $firstname[0]['safe_value'] . ' ' . $lastname[0]['safe_value'];
      }
      else {
        $user_name = $firstname[0]['safe_value'];
      }
    }
    else {
      $user_name = $variables['name'];
    }
    $variables['display_submitted'] = TRUE;
    $variables['submitted'] = t('By !username, !datetime', array('!username' => $user_name, '!datetime' => $variables['date']));
    $variables['user_picture'] = theme_get_setting('toggle_node_user_picture') ? theme('user_picture', array('account' => $node)) : '';
  }
  else {
    $variables['display_submitted'] = FALSE;
    $variables['submitted'] = '';
    $variables['user_picture'] = '';
  }
}

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
function callfire_custom_preprocess_comment(&$variables) {
    $author = t('!username', array('!username' => $variables['comment']->name));
  // Add pubdate to submitted variable.
  $variables['created'] = format_date($variables['comment']->created, 'custom', 'F j,Y g:i A T');
  $variables['pubdate'] = '<time pubdate datetime="' . format_date($variables['comment']->created, 'custom', 'c') . '">' . $variables['created'] . '</time>';
  $variables['submitted'] = t('Comment by ') . $author . t(' - !datetime', array('!datetime' => $variables['pubdate']));
}

/**
 * Returns HTML for a query pager.
 *
 * Menu callbacks that display paged query results should call theme('pager') to
 * retrieve a pager control so that users can view other results. Format a list
 * of nearby pages with additional query results.
 *
 * @param $variables
 *   An associative array containing:
 *   - tags: An array of labels for the controls in the pager.
 *   - element: An optional integer to distinguish between multiple pagers on
 *     one page.
 *   - parameters: An associative array of query string parameters to append to
 *     the pager links.
 *   - quantity: The number of pages in the list.
 *
 * @ingroup themeable
 */
function callfire_custom_views_mini_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('« first')), 'element' => $element, 'parameters' => $parameters));
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('newer »')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('« older')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last »')), 'element' => $element, 'parameters' => $parameters));

  if ($pager_total[$element] > 1) {
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next', 'left'),
        'data' => $li_next,
      );
    }

    if ($li_previous) {
      $items[] = array(
        'class' => array('pager-previous', 'right'),
        'data' => $li_previous,
      );
    }
    return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pager', 'clearfix')),
    ));
  }
}
/**
* Add unique class (mlid) to all menu items.
* with Menu title as class
*/

function callfire_custom_menu_link(array $variables) {
  $variables['element']['#attributes']['class'][] = 'menu-' . $variables['element']['#original_link']['mlid'];

  return theme_menu_link($variables);
}

/**
 * Theme preprocess function for theme_field() and field.tpl.php.
 *
 * @see theme_field()
 * @see field.tpl.php
 *
 * @param $variables
 *   An associative array containing:
 *   - label_hidden: A boolean indicating to show or hide the field label.
 *   - label: The label for the field.
 *   - items: An array of field items.
 *   - classes: A string containing the classes for the wrapping div.
 *   - attributes: A string containing the attributes for the wrapping div.
 *
 */

function callfire_custom_preprocess_field(&$variables) {
  if($variables['element']['#field_name'] == 'field_link') {
    $raw_link = $variables['element']['#items'][0];

    $gaEvent = "_gaq.push(['_trackEvent', 'Sign Up', '" . $raw_link['title'] . "', '". drupal_get_title() . " - Top']);";
    $variables['items'][0]['#markup'] = '<a href="'. $raw_link['url'] . '" class="' . $raw_link['attributes']['class'] . '" onclick="' . $gaEvent . '">' . $raw_link['title'] . '</a>';
  }
}

function callfire_custom_html_head_alter(&$head_elements) {
  unset($head_elements['system_meta_generator']);
  foreach ($head_elements as $key => $element) {
    if (isset($element['#attributes']['rel']) && $element['#attributes']['rel'] == 'shortlink') {
      unset($head_elements[$key]);
    }

    if (isset($element['#attributes']['rel']) && $element['#attributes']['rel'] == 'canonical' && $head_elements['rdf_node_title']['#attributes']['about'] == '/home') {
      $head_elements[$key]['#attributes']['href'] = base_path();
    }
    if (isset($element['#attributes']['rel']) && $element['#attributes']['rel'] == 'canonical' && $head_elements['rdf_node_title']['#attributes']['about'] == '/pricing-rates') {
      $head_elements[$key]['#attributes']['href'] = base_path()."pricing";
    }
  }
}


/**
 * Override for the profile attribute in the <head> tag in html.tpl.php
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */

function callfire_custom_preprocess_html(&$variables, $hook) {
  $variables['grddl_profile'] = 'http://www.w3.org/1999/xhtml/vocab/';
  if(arg(1) == 192001) {
    $variables['theme_hook_suggestions'][] =  'html__pricing';
  }
}
?>


