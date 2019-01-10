<?php
/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Article" it would result in "node-article". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. page, article, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>

<?php

$icon_counter = 0;
if(isset($content['field_member_employees'])) {
  $icon_counter++;
  if ($icon_counter % 2 == 0) {
    $field_member_employees_icon_position = 'icon-even';
  }
  else {
    $field_member_employees_icon_position = 'icon-odd';
  }
}
if(isset($content['field_member_web_presence_html'])) {
  $icon_counter++;
  if ($icon_counter % 2 == 0) {
    $field_member_web_presence_html_icon_position = 'icon-even';
  }
  else {
    $field_member_web_presence_html_icon_position = 'icon-odd';
  }
}
if(isset($content['field_member_brick_mortar_long'])) {
  $icon_counter++;
  if ($icon_counter % 2 == 0) {
    $field_member_brick_mortar_long_icon_position = 'icon-even';
  }
  else {
    $field_member_brick_mortar_long_icon_position = 'icon-odd';
  }
}
if(isset($content['field_memb_comm_involvement_long'])) {
  $icon_counter++;
  if ($icon_counter % 2 == 0) {
    $field_memb_comm_involvement_long_icon_position = 'icon-even';
  }
  else {
    $field_memb_comm_involvement_long_icon_position = 'icon-odd';
  }
}
if(isset($content['field_member_exports_long'])) {
  $icon_counter++;
  if ($icon_counter % 2 == 0) {
    $field_member_exports_long_icon_position = 'icon-even';
  }
  else {
    $field_member_exports_long_icon_position = 'icon-odd';
  }
}
if(isset($content['field_member_growth_long'])) {
  $icon_counter++;
  if ($icon_counter % 2 == 0) {
    $field_member_growth_long_icon_position = 'icon-even';
  }
  else {
    $field_member_growth_long_icon_position = 'icon-odd';
  }
}
if(isset($content['field_member_accomplishments'])) {
  $icon_counter++;
  if ($icon_counter % 2 == 0) {
    $field_member_accomplishments_icon_position = 'icon-even';
  }
  else {
    $field_member_accomplishments_icon_position = 'icon-odd';
  }
}
if(isset($content['field_member_twitter'])) {
  $icon_counter++;
  if ($icon_counter % 2 == 0) {
    $field_member_twitter_icon_position = 'icon-even';
  }
  else {
    $field_member_twitter_icon_position = 'icon-odd';
  }
}
if(isset($content['field_member_facebook'])) {
  $icon_counter++;
  if ($icon_counter % 2 == 0) {
    $field_member_facebook_icon_position = 'icon-even';
  }
  else {
    $field_member_facebook_icon_position = 'icon-odd';
  }
}

?>

<article class="node-member node-member--<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="member-header">
    <div class="member-wrapper">

      <div class="member-info">
        <?php if(isset($content['field_member_photo'])): ?>
          <div class="member-photo">
            <?php print render($content['field_member_photo']); ?>
          </div>
        <?php endif; ?>

        <div class="member-name">
          <h2><?php print render($title); ?></h2>
        </div>

        <div class="member-business">
          <?php print render($content['field_member_business_location']); ?>
        </div>

        <div class="member-highlights">
          <?php if(isset($content['field_member_employees'])): ?>
            <div class="member-icon member-employees <?php print $field_member_employees_icon_position; ?>">
              <?php print render($content['field_member_employees']); ?>
            </div>
          <?php endif; ?>

          <?php if(isset($content['field_member_web_presence_html'])): ?>
            <div class="member-icon member-web-presence <?php print $field_member_web_presence_html_icon_position; ?>">
              <?php print render($content['field_member_web_presence_html']); ?>
            </div>
          <?php endif; ?>

          <?php if(isset($content['field_member_brick_mortar_long'])): ?>
            <div class="member-icon member-brick-mortar <?php print $field_member_brick_mortar_long_icon_position; ?>">
              <?php print render($content['field_member_brick_mortar_long']); ?>
            </div>
          <?php endif; ?>

          <?php if(isset($content['field_memb_comm_involvement_long'])): ?>
            <div class="member-icon member-comm-involvement <?php print $field_memb_comm_involvement_long_icon_position; ?>">
              <?php print render($content['field_memb_comm_involvement_long']); ?>
            </div>
          <?php endif; ?>

          <?php if(isset($content['field_member_exports_long'])): ?>
            <div class="member-icon member-exports <?php print $field_member_exports_long_icon_position; ?>">
              <?php print render($content['field_member_exports_long']); ?>
            </div>
          <?php endif; ?>

          <?php if(isset($content['field_member_growth_long'])): ?>
            <div class="member-icon member-growth <?php print $field_member_growth_long_icon_position; ?>">
              <?php print render($content['field_member_growth_long']); ?>
            </div>
          <?php endif; ?>

          <?php if(isset($content['field_member_accomplishments'])): ?>
            <div class="member-icon member-accomplishments <?php print $field_member_accomplishments_icon_position; ?>">
              <?php print render($content['field_member_accomplishments']); ?>
            </div>
          <?php endif; ?>

          <?php if(isset($content['field_member_twitter'])): ?>
            <div class="member-icon member-twitter <?php print $field_member_twitter_icon_position; ?>">
              <?php print render($content['field_member_twitter']); ?>
            </div>
          <?php endif; ?>

          <?php if(isset($content['field_member_facebook'])): ?>
            <div class="member-icon member-facebook <?php print $field_member_facebook_icon_position; ?>">
              <?php print render($content['field_member_facebook']); ?>
            </div>
          <?php endif; ?>
        </div>

      </div><?php // .member-info ?>

      <div class="member-description">
          <div class="member-main">
            <h2><?php print t('About ');
                      if($content['field_member_business_name']){
                        print render($content['field_member_business_name']);
                      } else {
                        print render($title);
                      }; ?> &hellip;</h2>

            <?php print render($content['body']); ?>

            <?php if($content['field_member_quote']): ?>
              <blockquote>
                <?php
                  if (isset($content['field_member_quote']['#items'][0]['safe_value'])) {
                    print $content['field_member_quote']['#items'][0]['safe_value'];
                  }
                ?>
                <?php if($content['field_member_quote_source']): ?>
                  <p class="author"><?php print render($content['field_member_quote_source']); ?></p>
                <?php endif; ?>
              </blockquote>
            <?php endif; ?>
          </div>
      </div><?php // .member-description ?>

    </div><?php // .member-wrapper ?>
  </div><?php // .member-header ?>

  <?php
    hide($content['comments']);
    hide($content['links']);
  ?>

</article><!-- /.node -->
