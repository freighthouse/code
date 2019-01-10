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

<?php if($referer_path != '') : ?>
	<div class="back-to-book-button" data-related-book-id="<?php print $related_book_nid; ?>">
		<div class="button-container tabs header-overlay">
			<div class="container">
				<a href="<?php print $referer_path; ?>" type="button" class="btn">
					<i class="fa fa-long-arrow-left pull-left"></i>
					<span>Back to Search</span>
				</a>
			</div>
		</div>
	</div>
<?php elseif($related_book_path != '' && $referer_path == '') : ?>
	<div class="back-to-book-button" data-related-book-id="<?php print $related_book_nid; ?>">
		<div class="button-container tabs header-overlay">
			<div class="container">
				<a href="<?php print $related_book_path; ?>" type="button" class="btn">
					<i class="fa fa-long-arrow-left pull-left"></i>
					<span>Back to <?php print $related_book_name; ?></span>
				</a>
			</div>
		</div>
	</div>
<?php endif; ?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
	<?php if ($display_submitted): ?>
		<div class="submitted">
			<?php print $submitted; ?>
		</div>
	<?php endif; ?>
    <?php session_start(); ?>
    <?php $field_book_cover_uri = $_SESSION['field_book_cover_uri']; ?>
	<div class="content"<?php print $content_attributes; ?>>
		<?php
			// We hide the comments and links now so that we can render them later.
			hide($content['comments']);
			hide($content['links']);
		?>
	</div>

	<div class="container body">
		<div class="row">
			<div class="col-xs-12 col-sm-12 col-md-5 col-lg-5 resource-cover-wrapper">
				<!-- ---------------- -->
				<!-- Resource Cover   -->
				<!-- ---------------- -->
				<div class="row">
					<div class="col-xs-12">
						<div class="resource-cover book-cover">
							<img class="img-responsive" src="
								<?php if($field_book_cover_uri != '') {
									print $field_book_cover_uri;
								}else {
									print $field_image_uri;
								} ?>" />
						</div>
					</div>
				</div>

				<!-- ---------------- -->
				<!-- Buttons          -->
				<!-- ---------------- -->
				<div class="button-container support-material-options">
					<div class="row">
						<div class="col-xs-12 col-sm-12 col-md-12 pull-left">

		          <?php if(!empty($html_experience)) { ?>
		              <a href="<?php echo $html_experience ?>" target="_blank" class="btn btn-green">
										<i class="fa fa-share pull-right"></i>
										<span>Launch Web Resource</span>
									</a>
		          <?php }?>
		          <?php if ($type === 'Game') { ?>
		              <a href="<?php print $material_link;?>" target="_blank" class="btn btn-green">
										<i class="fa fa-share pull-right"></i>
										<span>Launch Puzzle</span>
									</a>
				  <?php } elseif ($type === 'Interactive Media') { ?>
				  	  <a href="<?php print $interactive_media;?>" target="_blank" class="btn btn-green">
										<i class="fa fa-share pull-right"></i>
										<span>Launch Interactive</span>
									</a>
				  <?php } elseif ($type === 'eBooks') { ?>
				  	  <a href="<?php print $ebook_reference;?>" target="_blank" class="btn btn-green">
										<i class="fa fa-share pull-right"></i>
										<span>Launch eBook</span>
									</a>
		          <?php } elseif (!$has_video || isset($pdf_uri)) { ?>
							<?php ?>

								<?php if($has_pdf === true): ?>
									<a href="<?php print $pdf_uri;?>" target="_blank" class="btn btn-green">
										<i class="fa fa-download pull-right"></i>
										<span>Download PDF</span>
									</a>
								<?php endif; ?>
						<?php	} ?>
						</div>

						<div class="col-xs-12 col-sm-12 col-md-12">
							<?php
								if(!user_is_anonymous()) {
									print $content['test_modal'];
								} else {
							?>
							<a href="/literacy-central/reasons-to-register" class="btn btn-blue">
                <i class="fa fa-heart-o"></i>
                <span>My Favorites</span>
							</a>
							<?php } ?>
						</div>

					</div>
				</div>
			</div>

			<div class="col-xs-12 col-sm-12 col-md-7 pull-right">
				<?php if($tabs): ?>
					<div id="tabs">
						<ul class="tabs primary">
							<?php print render($tabs); ?>
						</ul>
					</div>
				<?php endif; ?>

				<?php print $messages; ?>
				<!-- ------------------------ -->
				<!-- Resource Description     -->
				<!-- ------------------------ -->
				<div class="resource-description">
					<h1><?php print $title ?></h1>
					<h2>Source: <?php print $source ?></h2>
					<div class="row">
						<div class="col-xs-12">
							<div class="addthis_inline_share_toolbox_m0wb"></div>
							<p><?php print render($content['field_description']); ?></p>
						</div>
					</div>

				</div>

				<?php if($has_video) { ?>
				<!-- 16:9 aspect ratio -->
					<?php if($is_youtube) { ?>
						<div class="embed-responsive embed-responsive-16by9" style="margin-top:20px; margin-bottom: 20px;" >
							<iframe class="embed-responsive-item" src="<?php print $youtube_video_link; ?>" allowfullscreen></iframe>
						</div>
					<?php } ?>

					<?php if($is_vimeo) { ?>
						<div class="embed-responsive embed-responsive-16by9" style="margin-top:20px; margin-bottom: 20px;" >
							<iframe class="embed-responsive-item" src="<?php print $vimeo_video_link; ?>" allowfullscreen></iframe>
						</div>
					<?php } ?>


				<?php } ?>
				<!-- ------------------------ -->
				<!-- Resource Information     -->
				<!-- ------------------------ -->
				<?php if ($has_resource_info) { ?>
				<div class="resource-information">

					<h3>Resource Information</h3>

					<div class="panel panel-default">
						<div class="panel-body">
							<table class="table">
								<tbody>
								<?php foreach($table as $title => $value): ?>
									<tr>
										<td class="col-xs-4"><?php print render($title); ?></td>
										<td class="col-xs-8"><?php print render($value); ?></td>
									</tr>
								<?php endforeach; ?>
								</tbody>
							</table>
						</div>
					</div>

					<!--<h3>View Other Support Materials</h3>

					<div class="panel panel-default">
						<div class="panel-body">

							<div class="row">

								<div class="col-xs-4">
									<a href="book-resource.html">
										<div class="resource-image">
											<img class="img-responsive" src="assets/images/resource-image-test-7.jpg"  />
										</div>
									</a>
								</div>

								<div class="col-xs-8">
									<h3><a href="book-resource.html">Circle, Square, Moose</a></h3>
									<h4>by Kelly Bingham</h4>
									<p class="text">Moose loves shapes. In fact, he loves them so much, he has trouble letting the narrator tell the story!</p>
									<p class="grade-level">3rd Grade</p>
								</div>

							</div>

						</div>
					</div>-->

				</div>
				<?php } ?>

				<?php if($related_book_path) : ?>
					<p class="related-book-path"><a href="<?php echo $related_book_path; ?>">This resource supports <strong><?php echo trim($related_book_name); ?></strong>. See more support materials for <strong><?php echo $related_book_name; ?></strong>.</a></p>
				<?php endif; ?>

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
<?php unset($_SESSION['field_book_cover_uri']); ?>

