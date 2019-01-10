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
	hide($content['comments']);
	hide($content['links']);
?>
<?php $_SESSION['field_book_cover_uri'] = $field_book_cover_uri; ?>


<?php if($from_search != '') : ?>
<div class="back-to-book-button">
	<div class="button-container tabs header-overlay">
		<div class="container">
			<a href="<?php print $referer_path; ?>" type="button" class="btn active">
				<i class="fa fa-long-arrow-left pull-left"></i>
				<span>Back to Search</span>
			</a>
		</div>
	</div>
</div>
<?php endif; ?>
	<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

		<div class="content"<?php print $content_attributes; ?>>

			<div class="container body">

				<div class="row">

					<!-- ---------------- -->
					<!-- Resource Cover   -->
					<!-- ---------------- -->
					<div class="col-xs-12 col-sm-12 col-md-5 col-lg-5 resource-cover-wrapper">
						<div class="resource-cover book-cover">
							<img src="<?= $field_book_cover_uri ?>" class="img-responsive"/>
						</div>

					<!-- ------------------------ -->
					<!-- Button Container 2 of 2  -->
					<!-- ------------------------ -->
					<div class="hidden-xs hidden-sm button-container-wrapper">

						<div class="button-container">
							<div class="row">
								<div class="col-xs-12">
									<?php
										if(!user_is_anonymous()) {
											print $content['add_book_to_favorites_link'];
										} else {
									?>
									<a href="/literacy-central/reasons-to-register">
										<button type="button" class="btn btn-blue">
											<i class="fa fa-heart-o pull-right"></i>
											My Favorites
										</button>
									</a>
									<?php } ?>
								</div>
								<?php if ($has_overdrive_preview_link) : ?>
									<div class="col-xs-12 col-sm-12">
										<a href="<?php print $overdrive_preview_link ?> " target="_blank">
											<button type="button" class="btn btn-yellow-dark">
                                                <i class="fa fa-eye pull-right"></i><span>Book Preview</span>
											</button>
										</a>
									</div>
									<?php endif; ?>
                                <div class="col-xs-12 col-sm-12">
    								<?php if ($has_amazon_link) : ?>
    									<a href="<?php print $amazon_link ?> " target="_blank">
    										<button type="button" class="btn btn-green">
                                                <i class="fa fa-shopping-cart pull-right"></i><span>Amazon</span>
                                            </button>
    									</a>
    								<?php endif; ?>
    							</div>
							</div>
						</div>
					</div>
					</div>

					<!-- ------------------------ -->
					<!-- Resource Description     -->
					<!-- ------------------------ -->
					<div class="col-xs-12 col-sm-12 col-md-7 col-lg-7 resource-description-wrapper">
						<div class="resource-description">
							<?php if($tabs): ?>
								<div id="tabs">
									<ul class="tabs primary">
										<?php print render($tabs); ?>
									</ul>
								</div>
							<?php endif; ?>
							<?php print render($title_prefix); ?>
							<div class="content"<?php print $content_attributes; ?>>
								<h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
								<h2><?php print $contributors; ?></h2>
                                <div class="addthis_inline_share_toolbox_m0wb"></div>
								<p><?php print $description; ?></p>
							</div>
							<?php print render($title_suffix); ?>
						</div>
					</div>

					<!-- ------------------------ -->
					<!-- Button Container 1 of 2  -->
					<!-- ------------------------ -->
					<div class="col-xs-12 col-sm-12 col-md-5 col-lg-5 pull-left hidden-md hidden-lg button-container-wrapper">
						<div class="button-container">
							<div class="row">
								<div class="col-xs-12">
									<?php
										if(!user_is_anonymous()) {
											print $content['add_book_to_favorites_link'];
										} else {
									?>
									<a href="/literacy-central/reasons-to-register">
										<button type="button" class="btn btn-blue">
											<i class="fa fa-heart-o pull-right"></i>
											My Favorites
										</button>
									</a>
									<?php } ?>
									<!--<button type="button" class="btn btn-blue"><i class="fa fa-shopping-cart pull-right"></i><span>RIF</span></button>-->
								</div>
								<!-- <div class="col-xs-12 col-sm-6">
								<?php //if ($has_storefront_link) : ?>
								<a href="<?php //print $storefront_link ?> "target="_blank">
								<button type="button" class="btn btn-green"><i class="fa fa-shopping-cart pull-right"></i><span>RIF</span></button></a>
								<?php //endif; ?>
								</div> -->
								<?php if ($has_overdrive_preview_link) : ?>
								<div class="col-xs-12 col-sm-12">
										<a href="<?php print $overdrive_preview_link ?> " target="_blank">
											<button type="button" class="btn btn-yellow-dark">
                                                <i class="fa fa-eye pull-right"></i><span>Book Preview</span>
											</button>
										</a>
									</div>
									<?php endif; ?>
								<div class="col-xs-12 col-sm-12">
									<?php if ($has_amazon_link) : ?>
										<a href="<?php print $amazon_link ?> " target="_blank">
											<button type="button" class="btn btn-green">
                                                <i class="fa fa-shopping-cart pull-right"></i><span>Amazon</span>
											</button>
										</a>
									<?php endif; ?>
								</div>
							</div>
						</div>
					</div>

					<!-- ------------------------ -->
					<!-- Support Materials        -->
					<!-- ------------------------ -->
					<div class="col-xs-12 col-sm-12 col-md-7 col-lg-7 pull-right support-materials-wrapper">

						<div class="support-materials">
							<?php print $support_materials; ?>
						</div>

					</div>

					<!-- ------------------------ -->
					<!-- Resource Information     -->
					<!-- ------------------------ -->
					<div class="col-xs-12 col-sm-12 col-md-5 col-lg-5 pull-left resource-information-wrapper">
						<div class="resource-information">
							<div class="panel panel-default">
								<div class="panel-body">
									<table class="table">
										<tbody>
										<?php foreach ($table as $title => $value): ?>
											<tr>
												<td class="col-xs-4"><?php print render($title); ?></td>
												<td class="col-xs-8"><?php print render($value); ?></td>
											</tr>
										<?php endforeach; ?>
										</tbody>
									</table>
								</div>
							</div>
						</div>
					</div>

					<!-- ------------------------ -->
					<!-- Sponsors Information     -->
					<!-- ------------------------ -->
					<?php if (isset($content['field_sponsor'])):?>
						<div class="col-xs-12 col-sm-12 col-md-5 col-lg-5 pull-left sponsors-wrapper">
							<div class="col-xs-12 sidebar-sponsor resource-sponsor">
								<?php if (isset($content['field_sponsor_title'])):?>
							        <h2><?php print render($content['field_sponsor_title']); ?></h2>
								<?php else : ?>
									<h2>Made Possible By</h2>
								<?php endif; ?>
								<?php print render($content['field_sponsor']); ?>
							</div>
						</div>
					<?php endif; ?>

				</div>

			</div>
		</div>
	</div>
<?php /*print render($content); */ ?>
