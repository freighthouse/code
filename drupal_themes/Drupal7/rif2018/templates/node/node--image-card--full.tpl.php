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
	 * - $node_url: Direct URL of the current node.
	 * - $display_submitted: Whether submission information should be displayed.
	 * - $submitted: Submission information created from $name and $date during
	 *   template_preprocess_node().
	 * - $classes: String of classes that can be used to style contextually through
	 *   CSS. It can be manipulated through the variable $classes_array from
	 *   preprocess functions. The default values can be one or more of the
	 *   following:
	 *   - node: The current template type; for example, "theming hook".
	 *   - node-[type]: The current node type. For example, if the node is a
	 *     "Blog entry" it would result in "node-blog". Note that the machine
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
	 * - $type: Node type; for example, story, page, blog, etc.
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
	 * - $view_mode: View mode; for example, "full", "teaser".
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
	 * variable is defined; for example, $node->body becomes $body. When needing to
	 * access a field's raw values, developers/themers are strongly encouraged to
	 * use these variables. Otherwise they will have to explicitly specify the
	 * desired field language; for example, $node->body['en'], thus overriding any
	 * language negotiation rule that was previously applied.
	 *
	 * @see template_preprocess()
	 * @see template_preprocess_node()
	 * @see template_process()
	 *
	 * @ingroup themeable
	 */
?>

<?php
	// Placeholder Variables. These will be overwritten by Drupal. These same variables will be used so print these variables in the html for now and we will overwrite them later.
	// $title (already defined)
	if (!isset($body_text)) {
		$body_text = render($content['body']);
	}

	//Default Values
	//$img_align = 'left'; // left | right
	//$img_src = 'http://placehold.it/500x500';
	//$color = '#123456'; //Default title and button color.
	//$body_color = '#000'; // Default is a grayish color
	//$has_link = false; // true | false
	//$link = '<a href="#" >Link Title</a>';

	// To print a variable in php as html you will want to do surround in php tags [ print $variable_name; ]

	$pull_left = '';
	$push_right = '';
	if ($img_align == 'Left') :
		$pull_left = 'col-sm-pull-6';
		$push_right = 'col-sm-push-6';
	endif;
?>

<?php if ($field_use_new_style) { ?>
	<div class="node-image-card-new-style-container" style="background-color: white">
		<div class="container">
			<div class="node-image-card-new-style col-xs-12" style="background-color: white">
				<div class="row">
					<div class="col-md-4">
						<div class="imgContainer">
							<img class="img-responsive" src="<?php print $img_src; ?>">
						</div>
					</div>

					<div class="col-md-8">
            <!-- header title -->
            <?php if($center_header): ?>
            <h2 style="color: <?php print $color; ?>" class="h2Style">
              <?php print $display_title; ?>
            </h2>
            <?php endif; ?>
						<?php if(!$center_header): ?>
							<h2 style="color: <?php print $color; ?>" class="h2Style">
								<?php print $display_title; ?>
							</h2>
						<?php endif; ?>
						<!-- body text -->
						<div class="bodyText">
							<?php print $body_text; ?>
						</div>
						<!-- button -->
						<?php /*if(!$center_header):*/ ?>
                            <?php if($has_link): ?>
							<a href="<?php print $link_src; ?>"
							   class="btn btn-jumbotron urlButton btn-yellow-rif blue-border">
								<?php print $link_text; ?>
							</a>
                            <?php endif; ?>
            <?php /* endif; */ ?>
            <?php /* if($center_header): ?>
                        <?php if($has_link): ?>
        					<div class="col-xs-12">
        						<div class="jumbotron-button-container">
        							<a href="<?php print $link_src; ?>"
        							   class="btn btn-jumbotron urlButton btn-yellow-rif blue-border">
        								<?php print $link_text; ?>
        							</a>
        						</div>
        					</div>
                        <?php endif; ?>
					<?php endif;*/ ?>
					</div>
					
				</div>
			</div>
		</div>
	</div>
<?php } else { ?>
	<div class="node-image-card-container col-xs-12">
		<div class="panel panel-default">
			<div
				id="node-<?php print $node->nid; ?>"
				class="<?php print $classes; ?>
			clearfix"<?php print $attributes; ?>
			>
				<?php print render($title_prefix); ?>
				<?php print render($title_suffix); ?>

				<div class="row panelBodyProps">
					<div class="col-lg-6 textBox <?php print $push_right; ?>">
						<!-- header title -->
						<h2 style="color: <?php print $color; ?>" class="h2Style">
							<?php print $title; ?>
						</h2>
						<!-- body text -->
						<div class="bodyText">
							<?php print $body_text; ?>
						</div>
						<!-- button -->
						<a href="<?php print $link_src; ?>"
						   class="btn btn-jumbotron urlButton btn-yellow-rif blue-border">
							<?php print $link_text; ?>
						</a>
					</div>
					<?php if ($has_image) : ?>
						<div
							style="background-image: url(<?php print $img_src; ?>)"
							class="col-lg-6 imgContainer <?php print $pull_left; ?>">
						</div>
					<?php endif; ?>
				</div>
			</div>
		</div>
	</div>
<?php } ?>
