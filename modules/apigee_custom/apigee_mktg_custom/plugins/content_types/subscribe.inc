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
  'title' => t('Subscribe links'),
  'single' => TRUE,
  // 'icon' => 'icon_page.png',
  'description' => t('The row of subscribe links.'),
  'category' => t('Apigee custom'),
);

/**
 * Output function for the 'type_list' content type.
 */
function apigee_mktg_custom_subscribe_content_type_render($subtype, $conf, $panel_args) {

  $block = new stdClass();
  $output = '';

  if ($node = menu_get_object()) {
    $link = 'http://blog.apigee.com' . url('node/' . $node->nid);
    $text = urlencode($node->title);
    $output .= '<div class="subscribe">';
    $output .= '<a href="http://www.linkedin.com/company/apigee" class="linked">linked in</a>';
    $output .= '<a href="http://twitter.com/share?text=' . $text . '&url=' . $link . '" class="twitter">twitter</a>';
    $output .= '<a href="http://feeds.apigee.com/ApigeeBlog" class="rss">rss</a>';
    $output .= '<a href="https://plus.google.com/share?url=' . $link . '" class="gplus">gplus</a>';
    $output .= '<a href="http://www.facebook.com/sharer.php?u=' . $link . '" class="facebook">facebook</a>';
    $output .= '<a href="mailto:?subject=' . $node->title . '&body=' . $link . '" class="mail">mail</a>';
    $output .= '</div>';
    $block->content = $output;
  }

  return $block;
}
