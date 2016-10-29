<?php

define('PRODUCTS_VOCABULARY_ID', 2);
define('EMAILS_TERM_ID', 9);
define('SIMPLENEWS_PAGE_ID', 23);

function phptemplate_breadcrumb($breadcrumb) 
{
    if (!empty($breadcrumb)) {
        return '<div class="breadcrumb">'. implode(' › ', $breadcrumb) .'</div>';
    }
}

function phptemplate_preprocess_comment_wrapper(&$vars) 
{
    if ($vars['content'] && $vars['node']->type != 'forum') {
        $vars['content'] = '<h2 class="comments">'. t('Comments') .'</h2>'.  $vars['content'];
    }
}

function phptemplate_menu_local_tasks() 
{
    return menu_primary_local_tasks();
}

function phptemplate_comment_submitted($comment) 
{
    return t(
        '!datetime — !username',
        array(
        '!username' => theme('username', $comment),
        '!datetime' => format_date($comment->timestamp)
        )
    );
}

function phptemplate_node_submitted($node) 
{
    return t(
        '!datetime — !username',
        array(
        '!username' => theme('username', $node),
        '!datetime' => format_date($node->created),
        )
    );
}

function phptemplate_get_ie_styles() 
{
    $iecss = '<link type="text/css" rel="stylesheet" media="all" href="'. base_path() . path_to_theme() .'/ie.css" />';
    return $iecss;
}

function phptemplate_preprocess_page(&$vars) 
{
    $vars['tabs2'] = menu_secondary_local_tasks();
    if (module_exists('path')) {
        $alias = drupal_get_path_alias(str_replace('/edit', '', $_GET['q']));
        if ($alias != $_GET['q']) {
            $suggestions = array();
            $template_filename = 'page';
            foreach (explode('/', $alias) as $path_part) {
                $template_filename = $template_filename . '-' . $path_part;
                $suggestions[] = $template_filename;
            }
            $vars['template_files'] = array_merge((array) $suggestions, $vars['template_files']);
        }
    }
    //todo i think this can be deleted
    if(arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
        $termid = arg(2);
        $parent_term = taxonomy_get_parents($termid);
        if(key($parent_term) == EMAILS_TERM_ID) {
            $term = taxonomy_get_term($termid);
            $vars['template_file'] = 'page-taxonomy-term-emails';
        }
    }
}
/* todo delete
function MNIMobile_theme() {
  return array(
	'simplenews_block_form_17' => array(
      'template' => 'simplenews-block-form',
	  'arguments' => array('form' => NULL)
    )
  );
}
*/
/* Allow for templates by content type */
function MNIMobile_preprocess_page(&$variables) 
{
    if ($variables['node']->type != "") {
        $variables['template_files'][] = "page-" . $variables['node']->type;
    }
}


function MNIMobile_menu_item_link($link) 
{
    
    $targetnid=str_replace('node/', '', $link['href']);
    $targettype = db_fetch_object(db_query('SELECT type FROM {node} WHERE nid=%d', $targetnid));
    if($link['tab_parent'] != 'admin/%' && $targettype->type=="mobile_product_page") {
        //echo "~~".$targetnid."##".$targettype->type."^^".$link['tab_parent']."$$".($link['tab_parent'] == 'node/%' && $targettype->type ="mobile_product_page")."**";
        if (empty($link['localized_options'])) {
            $link['localized_options'] = array();
        }
        $link['localized_options']['html']="true";
        return '<h2 class="mobile_product_page_menu">'.l($link['title'], $link['href'], $link['localized_options']).'</h2><span>'.l('[see more and subscribe]', $link['href'], $link['localized_options']).'</span>';
    }else{
        return theme_menu_item_link($link);
    }
}


function MNIMobile_menu_item($link, $has_children, $menu = '', $in_active_trail = false, $extra_class = null) 
{
    if(strpos($link, "mobile_product_page_menu")!==0) {
        if ($in_active_trail) {
            $class .= ' active-trail';
        }
        return '<li>'. $link . $menu .'</li>';
    }else{
        return theme_menu_item($link);
    }
}

function MNIMobile_preprocess_search_result(&$variables) 
{
    $t = $variables['info_split']['type'];
    $d = date("Y-m-d H:i", $variables['result']['node']->created);
    $variables['info_split'] = array('type' => $t, 'date' => $d);
    $variables['info'] = "$t - $d";
}
