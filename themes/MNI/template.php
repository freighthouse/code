<?php

# @author: Jeremy Cerda
# @version: $Id: template.php 2750 2011-10-11 18:59:48Z jcerda $

session_start();

$template_path = base_path() . path_to_theme();
define('template_path', $template_path);

function phptemplate_breadcrumb($breadcrumb) {
	if (!empty($breadcrumb)) {
		return '<div class="breadcrumb">'. implode(' › ', $breadcrumb) .'</div>';
	}
}

function phptemplate_preprocess_comment_wrapper(&$vars) {
	if ($vars['content'] && $vars['node']->type != 'forum') {
		$vars['content'] = '<h2 class="comments">'. t('Comments') .'</h2>'.  $vars['content'];
	}
}

function phptemplate_menu_local_tasks() {
	return menu_primary_local_tasks();
}


function phptemplate_node_submitted($node) {
	return t('!datetime — !username',
		array(
			'!username' => theme('username', $node->uid),
			'!datetime' => format_date($node->created),
		));
}

function phptemplate_get_ie_styles() {
	$iecss = '<link type="text/css" rel="stylesheet" media="all" href="'. base_path() . path_to_theme() .'/ie.css" />';
	return $iecss;
}
//remove the filter tips under the comment form
function phptemplate_filter_tips($tips, $long = false, $extra = '') {
	return '';
}
//remove the link to more filter tips under the comment form
function phptemplate_markup($element) {
	if (stristr($element['#value'] , "filter/tips")){
		return '';
	}
	return theme_markup($element);
}

/**
* Implementation of HOOK_theme().
*/

function MNI_theme(&$existing, $type, $theme, $path) {
 return array(
   // tell Drupal what template to use for the user register form
    'user_login' => array(
      'template' => 'user-login',
      'arguments' => array('form' => NULL),
      ),
	);
}


function MNI_preprocess_user_login(&$variables) {
	$variables['form']['name']['#description'] = "";
  $variables['form']['pass']['#description'] = "";

  if ($variables['form']['form_id']['#value'] == 'user_login'){
    $variables['form']['fbconnect_button'] = array();
   }

  $variables['rendered'] = drupal_render($variables['form']);
}

function MNI_preprocess_user_profile($vars) {
  //remove the order link from the main profile page - it remains on the order tab
  $vars['user_profile']=str_replace($vars['account']->content['orders']['link']['#value'],'',$vars['user_profile']);
  $vars['user_profile']=str_replace($vars['account']->content['orders']['#title'],'',$vars['user_profile']);
}

/* Allow for templates by content type */
function MNI_preprocess_page(&$variables) {
  $path = $_GET['q'];
  if (module_exists('path'))
    $path = drupal_get_path_alias($path);

  switch($path) {
    case (preg_match('/^home$/',$path) ? true : false):
    case (preg_match('/^sector\/.*/',$path) ? true : false):
      drupal_add_js(path_to_theme().'/js/show_teasers.js','theme');
      break;
  }

  if ($variables['node']->type != "") {
    $variables['template_files'][] = "page-" . $variables['node']->type;
  }
}


function phptemplate_preprocess_page(&$vars) {

	//allow for templates by path
	$vars['tabs2'] = menu_secondary_local_tasks();
	if (module_exists('path')) {
		$alias = drupal_get_path_alias(str_replace('/edit','',$_GET['q']));
		if ($alias != $_GET['q']) {
			$suggestions = array();
			$template_filename = 'page';
			foreach (explode('/', strtolower ($alias)) as $path_part) {
				$template_filename = $template_filename . '-' . $path_part;
				$suggestions[] = $template_filename;
			}
			$vars['template_files'] = array_merge((array) $suggestions, $vars['template_files']);
		}
	}

	//unrelated feature to split comments out of $content so they can be displayed differently
	if($vars['node']->type=="subscription_article"){
	  $vars['comments'] = $vars['comment_form'] = '';
	  /*if (module_exists('comment') && isset($vars['node'])) {*/
	    $vars['comments'] = comment_render($vars['node']);
	    $vars['comment_form'] = drupal_get_form('comment_form', array('nid' => $vars['node']->nid));
	  /*}*/
	}
}

//output real name instead of username for comments and chat
function MNI_comment_submitted($comment) {
	  return t('Posted by !username on @date at about @time.', array(
      '!username' => theme('username', $comment),
	    '@date' => format_date($comment->timestamp, 'custom', 'l, F j, Y'),
	    '@time' => format_date($comment->timestamp, 'custom', 'H:i')
	  ));
	}

function MNI_username($object) {
  if ($object->uid) {

  	if(!empty($object->profile_display_name)){
			$object->name = $object->profile_display_name;
		}else {
			$commenter=user_load($object->uid);
			if(!empty($commenter->profile_display_name)){
				$object->name = $commenter->profile_display_name;
			}

		}
  	//don't show email addresses
  	if(isEmail($object->name) ){
  		//just show the first part before the domain name?
 			$object->name=substr($object->name,0,strpos($object->name,"@"))."...";
  	}

   // Shorten the name when it is too long or it will break many tables
   //is this really needed? I don't know what tables the comment above refers to but it's from the base user module function.  put it back in if there's problems... TODO?.
   // if (drupal_strlen($object->name) > 20) {
   //   $name = drupal_substr($object->name, 0, 15) . '...';
   // }
   // else {
      $name = $object->name;
   // }
  	$output = check_plain($name);
  }
  else if ($object->name) {
    // Sometimes modules display content composed by people who are
    // not registered members of the site (e.g. mailing list or news
    // aggregator modules). This clause enables modules to display
    // the true author of the content.
    if (!empty($object->homepage)) {
      $output = l($object->name, $object->homepage, array('attributes' => array('rel' => 'nofollow')));
    }
    else {
      $output = check_plain($object->name);
    }

    $output .= ' (' . t('not verified') . ')';
  }
  else {
    $output = check_plain(variable_get('anonymous', t('Anonymous')));
  }

  return $output;
}



// Nice Menus
function MNI_nice_menus_build($menu, $depth = -1, $trail = NULL) {
  $output = '';
  // Prepare to count the links so we can mark first, last, odd and even.
  $index = 0;
  $count = 0;
  foreach ($menu as $menu_count) {
    if ($menu_count['link']['hidden'] == 0) {
      $count++;
    }
  }
  // Get to building the menu.
  foreach ($menu as $menu_item) {
		//only subscribers see the dashboard link
		if($menu_item['link']['link_path'] == "node/1773" && !mni_misc_functions_is_user_a_subscriber()){
			$menu_item['link']['hidden']=1;
		}

    $mlid = $menu_item['link']['mlid'];
    // Check to see if it is a visible menu item.
    if (!isset($menu_item['link']['hidden']) || $menu_item['link']['hidden'] == 0) {
      // Check our count and build first, last, odd/even classes.
      $index++;
      $first_class = $index == 1 ? ' first ' : '';
      $oddeven_class = $index % 2 == 0 ? ' even ' : ' odd ';
      $last_class = $index == $count ? ' last ' : '';
      // Build class name based on menu path
      // e.g. to give each menu item individual style.
      // Strip funny symbols.
      $clean_path = str_replace(array('https://','http://', 'www', '<', '>', '&', '=', '?', ':', '.'), '', $menu_item['link']['href']);
      // Convert slashes to dashes.
      $clean_path = str_replace('/', '-', $clean_path);
      $class = 'menu-path-'. $clean_path;
      if ($trail && in_array($mlid, $trail)) {
        $class .= ' active-trail';
      }
      // If it has children build a nice little tree under it.
      if ((!empty($menu_item['link']['has_children'])) && (!empty($menu_item['below'])) && $depth != 0) {
        // Keep passing children into the function 'til we get them all.
        $children = theme('nice_menus_build', $menu_item['below'], $depth, $trail);
        // Set the class to parent only of children are displayed.
        $parent_class = ($children && ($menu_item['link']['depth'] <= $depth || $depth == -1)) ? 'menuparent ' : '';
				if ($menu_item['link']['options']['attributes']['title'] == 'drop_title'){
					//print_r($menu_item);
					$output .= '<div class="column">'. theme('menu_item_link', $menu_item['link'], true);
				}else{
					$output .= '<li class="menu-' . $mlid . ' ' . $parent_class . $class . $first_class . $oddeven_class . $last_class .'">'. theme('menu_item_link', $menu_item['link']);
				}
        // Check our depth parameters.
        if ($menu_item['link']['depth'] <= $depth || $depth == -1) {
          // Build the child UL only if children are displayed for the user.
          if ($children) {
						if ($menu_item['link']['depth'] == 1){
							$flag_pos_col = NULL;
							$flag_pos_col = strpos($children,'"column"');
							//print $flag_pos_col;
							if ($flag_pos_col){
								$output .= '<div class="drop columns2"><div class="bg">';
							}else{
								$output .= '<div class="drop"><div class="bg">';
							}
						}
						if($flag_pos_col){
							$output .= '';
						}elseif($menu_item['link']['depth'] == 1){
							$output .= '<div class="column"><ul>';
						}else{
							$output .= '<ul>';
						}
						$output .= $children;
						if($flag_pos_col){
							$output .= '';
						}elseif($menu_item['link']['depth'] == 1){
							$output .= '</ul></div>';
						}else{
							$output .= "</ul>\n";
						}
						if ($menu_item['link']['depth'] == 1){
							$output .= '</div></div>';
						}
          }
        }
				if ($menu_item['link']['options']['attributes']['title'] == 'drop_title'){
					$output .= "</div>\n";
				}else{
					$output .= "</li>\n";
				}
      }
      else {
				if ($menu_item['link']['options']['attributes']['title'] == 'drop_title'){
					$output .= '<div class="column">'. theme('menu_item_link', $menu_item['link'], true).'</div>';
				}else{
					$output .= '<li class="menu-' . $mlid . ' ' . $class . $first_class . $oddeven_class . $last_class .'">'. theme('menu_item_link', $menu_item['link']) .'</li>'."\n";
				}
      }
    }
  }
  return $output;
}

function MNI_nice_menus($id, $menu_name, $mlid, $direction = 'right', $depth = -1, $menu = NULL) {
  $output = array();

  if ($menu_tree = theme('nice_menus_tree', $menu_name, $mlid, $depth, $menu)) {
    if ($menu_tree['content']) {
      $output['content'] = '<ul id="nav">'. $menu_tree['content'] .'</ul>'."\n";
      $output['subject'] = $menu_tree['subject'];
    }
  }
  return $output;

}


function MNI_menu_item_link($link, $custom=false) {
  if (empty($link['localized_options'])) {
    $link['localized_options'] = array();
  }

	if ($custom){
		return l_custom($link['title'], $link['href'], $link['localized_options']);
	}else{
		return l($link['title'], $link['href'], $link['localized_options']);
	}
}

function l_custom($text, $path, $options = array()) {
  global $language;

  // Merge in defaults.
  $options += array(
      'attributes' => array(),
      'html' => FALSE,
    );

  // Append active class.
  if (($path == $_GET['q'] || ($path == '<front>' && drupal_is_front_page())) &&
      (empty($options['language']) || $options['language']->language == $language->language)) {
    if (isset($options['attributes']['class'])) {
      $options['attributes']['class'] .= ' active';
    }
    else {
      $options['attributes']['class'] = 'active';
    }
  }

  // Remove all HTML and PHP tags from a tooltip. For best performance, we act only
  // if a quick strpos() pre-check gave a suspicion (because strip_tags() is expensive).
  if (isset($options['attributes']['title']) && strpos($options['attributes']['title'], '<') !== FALSE) {
    $options['attributes']['title'] = strip_tags($options['attributes']['title']);
  }

  return '<strong class="title">'. ($options['html'] ? $text : check_plain($text)) .'</strong>';
}

//overriding this from notifications_content.pages.inc to change text strings
function MNI_notifications_content_page_thread($account = NULL) {
  global $user;
  if (is_null($account)) {
    $account = $user;
  }
  // query string for node subscriptions
  $query = "SELECT s.*, f.value AS nid, n.type AS node_type, n.title FROM {notifications} s
    INNER JOIN {notifications_fields} f ON s.sid = f.sid LEFT JOIN {node} n ON f.intval = n.nid
    WHERE s.uid = %d AND s.type = 'thread' AND s.event_type = 'node' AND s.conditions = 1 AND f.field = 'nid'
    ORDER BY node_type, n.title";
  $results = pager_query($query, NOTIFICATIONS_CONTENT_PAGER, 0, NULL, $account->uid);

  $subscriptions = $list = array();
  $content_types = notifications_content_types('name');
  while ($sub = db_fetch_object($results)) {
    $subscriptions[$sub->nid] = $sub;
    $list[$sub->nid] = /*'['. $content_types[$sub->node_type] .'] '.*/ l($sub->title, 'node/'. $sub->nid);
  }

  if (!$subscriptions) {
    $output = t('You are not currently signed up for any alerts');
  }
  else {
    //$output = t('You are currently subscribed to the following threads:');
    $defaults = array('type' => 'thread', 'event_type' => 'node');
    $options = array('title' => t('Title'));
    $output .= drupal_get_form('notifications_user_form', $account, 'thread', $subscriptions, $list, $defaults, $options);
    $output .= theme('pager', NULL, NOTIFICATIONS_CONTENT_PAGER);
  }
  return $output;
}


function MNI_taxonomy_link($node = NULL) {
  if ($node != NULL) {
    $links = array();
    // If previewing, the terms must be converted to objects first.
/*
    if (isset($node->build_mode) && $node->build_mode == NODE_BUILD_PREVIEW) {
      $node->taxonomy = taxonomy_preview_terms($node);
    }
*/
    if (!empty($node->taxonomy)) {
      foreach ($node->taxonomy as $term) {
        // During preview the free tagging terms are in an array unlike the
        // other terms which are objects. So we have to check if a $term
        // is an object or not.
        if (is_object($term)) {
					if($term->vid==2){ //limit it to mni terms vocabulary
	          $links['taxonomy_term_'. $term->tid] = array(
	            //'title' => ($term->description && $term->description!="" ?$term->description :$term->name),
	            'title' => $term->name,
	            'href' => taxonomy_term_path($term),
	            'attributes' => array('rel' => 'tag', 'title' => strip_tags($term->description))
	          );
	        }
        }

        /*
        // Previewing free tagging terms; we don't link them because the
        // term-page might not exist yet.
        else {
          foreach ($term as $free_typed) {
            $typed_terms = drupal_explode_tags($free_typed);
            foreach ($typed_terms as $typed_term) {
              $links['taxonomy_preview_term_'. $typed_term] = array(
                'title' => $typed_term,
              );
            }
          }
        }
        */

      }
    }

    // We call this hook again because some modules and themes
    // call taxonomy_link('taxonomy terms') directly.
    drupal_alter('link', $links, $node);

    return $links;
  }
}

function MNI_taxonomy_subhed($node = NULL) {
	//get a taxonomy term to use as subhed.
	//Todo - better business logic?
  if ($node != NULL && !empty($node->taxonomy)) {
      foreach ($node->taxonomy as $term) {
        if (is_object($term) && ($term->vid==1 || $term->vid==2)) { //limit it to products and mni terms vocabularies
        	$current_term=$term->name;
       		break;
        }
      }
    return $current_term;
  }
}






/**
 * Return a themed list of items.
 *
 * @param $items
 *   An array of items to be displayed in the list. If an item is a string,
 *   then it is used as is. If an item is an array, then the "data" element of
 *   the array is used as the contents of the list item. If an item is an array
 *   with a "children" element, those children are displayed in a nested list.
 *   All other elements are treated as attributes of the list item element.
 * @param $title
 *   The title of the list.
 * @param $type
 *   The type of list to return (e.g. "ul", "ol")
 * @param $attributes
 *   The attributes applied to the list element.
 * @return
 *   A string containing the list output.
 */

function MNI_simple_item_list($items = array()) {
  if (!empty($items)) {
    $output .= "<ul>";
    $num_items = count($items);
    foreach ($items as $i => $item) {
      $attributes = array();
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      $output .= '<li>'. $data ."</li>\n";
    }
    $output .= "</ul>";
  }
  return $output;
}


/*CHATROOM related */
/**
 * Format the list of users in a chatroom.
 *
 * @param mixed $users
 * @param mixed $node
 * @return string
 */

 /* this is an override of the function in the module to remove some links that don't seem useful and are confusing */
function mni_chatroom_user_list($users, $node) {
  global $user;
  $is_admin = $user->uid == $node->uid || user_access('administer chats');

  $html = '<div id="chatroom-user-list-wrapper"><ul id="chatroom-user-list">';
  $preset = FALSE;
  if (module_exists('imagecache') && $node->chat->imagecache_preset) {
    $preset = imagecache_preset_by_name($node->chat->imagecache_preset);
  }
  foreach ($users as $chat_user) {
    $class = 'chatroom-user' . ($chat_user->sid == session_id() ? ' chatroom-current-user' : '');
    $id = 'chatroom_' . ($chat_user->uid ? "user_$chat_user->uid" : "guest_$chat_user->guest_id");
    $html .= '<li id="' . $id . '" class="' . $class . '">';
    if ($chat_user->uid && $node->chat->profile_picture && $chat_user->picture) {
      if ($preset) {
        $alt = t("@user's picture", array('@user' => $chat_user->name));
        $chat_user->picture = theme('imagecache', $preset['presetname'], $chat_user->picture, $alt, $alt);
        $html .= $chat_user->picture . theme('username', $chat_user);
      }
      else {
        $html .= theme('user_picture', $chat_user);
      }
    }
    else {
      $html .= theme('username', $chat_user);
    }

    $html.= '</li>';
  }
  $html .= '</ul></div>';
  return $html;
}

function MNI_chatroom_message_username($message, $skip_permission_check = FALSE) {
  return check_plain(theme('username', user_load(array('name' => $message->name))));
}

/**
 * Wrapper around theme('chatroom_message').
 *
 * @param mixed $message
 * @param mixed $node
 */
 /* override chatroom function to always theme username */
function MNI_chatroom_chat_get_themed_message($message, $node) {
	/* always theme username */
  //if ($message->uid && user_access('access user profiles')) {
  if ($message->uid ) {
    $username = theme('chatroom_message_username', $message);
  }
  else {
    $username = $message->name;
  }
  $public_css_class = variable_get('chatroom_msg_public_class', 'chatroom-msg');
  $private_css_class = variable_get('chatroom_msg_private_class', 'chatroom-private');
  $class = "new-message $public_css_class" . ($message->msg_type == 'private_message' ? " $private_css_class" : '');
  $output = '<div class="' . $class . '">';
  $output .= '(' . chatroom_get_message_time_string($message->modified) . ') <strong>' . $username . ':</strong> ';
  $output .= theme('chatroom_message', $message, $node);
  $output .= "</div>";
  return $output;
}

function MNI_chatroom_messages(array $messages, $node) {
  $output = '';
  foreach($messages as $message) {
    $output .= MNI_chatroom_chat_get_themed_message($message, $node);
  }
  return $output;
}

function MNI_chatroom_chat($node) {
  global $user;

  $output = '<style type="text/css">#chatroom-board-container { width: ' . variable_get('chatroom_message_board_width', '100%') . ';}</style>';
  $output .= "<strong>Users in this chat:</strong>";
  $output .= theme('chatroom_user_list', $node->chat->users, $node);
  $output .= '<div id="chatroom-board-container">';
  $output .= '<div id="chatroom-board">';
  foreach ($node->chat->latest_messages as $message) {
    $output .= MNI_chatroom_chat_get_themed_message($message, $node);
  }
  $output .= '</div></div>';
  $output .= theme('chatroom_buttons', $node);
  if ($node->uid == $user->uid || user_access('administer chats')) {
    $output .= drupal_get_form('chatroom_chat_management_form', $node);
  }
  return $output;
}
function MNI_chatroom_chat_kicked_user($node) {
  $msg = t('Chat closed.');
  return '<div id="chatroom-kicked-msg">'. $msg .'</div>';
}

function MNI_preprocess_search_result(&$variables) {
  $t = $variables['info_split']['type'];
  $d = date("Y-m-d H:i", $variables['result']['node']->created);
  $variables['info_split'] = array('type' => $t, 'date' => $d);
  $variables['info'] = "$t - $d";
}

//filefield mod to open in new window

function MNI_filefield_file($file) {
  // Views may call this function with a NULL value, return an empty string.
  if (empty($file['fid'])) {
    return '';
  }
  $path = $file['filepath'];
  $url = file_create_url($path);
  $icon = theme('filefield_icon', $file);
  // Set options as per anchor format described at
  $options = array(
    'attributes' => array(
      'type' => $file['filemime'] . '; length=' . $file['filesize'],
    ),
  );
  // Use the description as the link text if available.
  if (empty($file['data']['description'])) {
    $link_text = $file['filename'];
  }
  else {
    $link_text = $file['data']['description'];
    $options['attributes']['title'] = $file['filename'];
  }
  //open files of particular mime types in new window
  $new_window_mimetypes = array(
    'application/pdf',
    'text/plain'
  );
  if (in_array($file['filemime'], $new_window_mimetypes)) {
    $options['attributes']['target'] = '_blank';
  }
  return '<div class="filefield-file clear-block">'. $icon . l($link_text, $url, $options) .'</div>';
}
?>
