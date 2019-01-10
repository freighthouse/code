<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */



  // Get the node ID
  $node_id = $variables['view']->result[0]->nid;
  // Load the node
  $this_node = node_load($node_id);
  // Get the path alias
  $this_alias = $GLOBALS['base_url'] . '/' . drupal_get_path_alias('node/' . $node_id);

  // Get the metatags node title
  if (isset($this_node->metatags['en']['title']['value'])) {
    $this_title = token_replace($this_node->metatags['en']['title']['value'], array('node' => $this_node));
  }
  else {
    $this_title = $this_node->title;
  }

  // Get the metatags node description
  if (isset($this_node->metatags['en']['description']['value'])) {
    $this_description = token_replace($this_node->metatags['en']['description']['value'], array('node' => $this_node));
  }
  else {
    $this_description = $this_node->body['und'][0]['safe_summary'];
  }
  $this_description = strip_tags($this_description);

  if (isset($this_node->metatags['en']['twitter:title']['value'])) {
    $metatag_twitter_title = token_replace($this_node->metatags['en']['twitter:title']['value'], array('node' => $this_node));
  }
  else {
    $metatag_twitter_title = $this_title;
  }

  if (isset($this_node->metatags['en']['twitter:description']['value'])) {

    // Store the value with tokens
    $result = $this_node->metatags['en']['twitter:description']['value'];
    // Convert the tokens
    $metatag_twitter_description = token_replace($result, array('node' => $this_node));
    // Check for failed token conversion (empty tokens fail to convert)
    $pos = strpos($metatag_twitter_description, array('node' => $this_node), 'node:');

    // Check to see if the token was empty
    if ($pos !== false) {
      // Define the regex
      $regex = '/\[.\w*:\w*\] ?/';
      // Remove the empty token
      $metatag_twitter_description = preg_replace($regex, '', $metatag_twitter_description);
    }
    $metatag_twitter_description = strip_tags($metatag_twitter_description);

  }
  else {
    $metatag_twitter_description = $this_description;
  }

  // Shorten the twitter post
  $link_len = strlen($this_alias);
  $desc_len = strlen($metatag_twitter_description);
  $total_len = $link_len + $desc_len + 1;
  if ($total_len >= 140) {
    $new_len = $desc_len - ($link_len + 10);
    $metatag_twitter_description = mb_substr($metatag_twitter_description, 0, mb_strpos($metatag_twitter_description, ' ', $new_len)) . '...';
  }
?>
<h2>Share</h2>
<ul class="issue-share menu">
  <li class="first leaf">
    <a target="_blank" onclick="window.open(this.href, 'social-share',
'left=20,top=20,width=500,height=500,toolbar=0,resizable=0'); return false;" href="http://www.facebook.com/sharer.php?u=<?php print $this_alias; ?>" class="social-media-facebook-square">
      <span class="visuallyhidden">Facebook</span></a>
  </li>
  <li class="leaf">
    <a target="_blank" onclick="window.open(this.href, 'social-share',
'left=20,top=20,width=500,height=500,toolbar=0,resizable=0'); return false;" href="https://twitter.com/share?text=<?php print $metatag_twitter_description; ?>&url=<?php print $this_alias; ?>" class="social-media-twitter">
      <span class="visuallyhidden">Twitter</span>
    </a>
  </li>
  <li class="leaf">
    <a target="_blank" onclick="window.open(this.href, 'social-share',
'left=20,top=20,width=680,height=339,toolbar=0,resizable=0'); return false;" href="https://plus.google.com/share?url=<?php print $this_alias; ?>" class="social-media-googleplus">
      <span class="visuallyhidden">Google+</span>
    </a>
  </li>
  <li class="leaf">
    <a target="_blank" onclick="window.open(this.href, 'social-share',
'left=20,top=20,width=500,height=500,toolbar=0,resizable=0'); return false;" href="https://www.linkedin.com/shareArticle?mini=true&url=<?php print $this_alias; ?>&title=<?php print $this_title; ?>&summary=<?php print $this_description; ?>&source=<?php print $this_alias; ?>" class="social-media-linkedin-square">
      <span class="visuallyhidden">LinkedIn</span>
    </a>
  </li>
</ul>