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
//	$lines = explode("\n", $definitions);
//	$words = [];
//	$clues = [];
//	$errors = [];
//	foreach ($lines as $line) {
//		$matched = preg_match('/^((\d+).)?\s*([^:]+):(.*)$/', $line, $matches);
//		if ($matched) {
//			$words[] = trim($matches[4]);
//			$clues[] = trim($matches[3]);
//		} else {
//			$errors[] = $line;
//		}
//	}
	// dsm($def_words);
	// dsm($def_clues);
	// dsm($def_errors);
//	dsm('$words');
//	dsm($words);
//	dsm('$clues');
//	dsm($clues);
//	dsm('$errors');
//	dsm($errors);
	$printing = substr($_SERVER['REQUEST_URI'], 0, 6) === '/print';
?>

<style type="text/css">

	<?php // I moved this to src/assets/css/print.css ?>

<?php if (!$printing) { ?>
    #words > div > div.inner {
        border-radius: 8px;
        text-align: center;
        background-color: #146da8;
        text-transform: uppercase;
        font-weight: bold;
        padding: 12px 6px;
        margin: 6px;
    }
<?php } else { ?>
	#words {
		margin-bottom: 60px;
	}
    #words > div {
        width: 24%;
        display: inline-block;
        text-align: center;
    }
	.puzzle-title {
		margin-bottom: 15px;
	}
	.puzzle-box-container {
		max-width: 100%;
	}
	html, body {
		width: 100%;
		height: 100%;
	}
	@page {
		size: letter;
		margin: .5in 0.5in 0.5in;
	}
	.page-container {
		position: relative;
		bottom: 0;
		top: 0;
		left: 0;
		right: 0;
		min-height: 10in;
		width: 7.5in;
		margin: 0 auto;
		page-break-after: always;
	}
	.print-content {
		max-width: 7.5in;
		overflow: hidden;
	}
	.answer-key {
		page-break-before: always;
	}
<?php } ?>
</style>

<?php /*if ($printing) { */?><!--
	<div class="print-logo">
		<img class="print-logo" id="logo" typeof="foaf:Image" src="/sites/all/themes/custom/rif/public/assets/images/RIF_Primary_Horizontal.png" alt="RIF.org">
	</div>
--><?php /*} */?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

	<div class="puzzle-header-row">

		<div class="container">

			<div class="content col-md-3 col-xs-12 centered">

				<?php if (!$printing) { ?>

					<img src="/sites/all/themes/custom/rif/public/assets/images/puzzles/icon_crossword.png">

				<?php } ?>

			</div>

			<div class="content col-md-6 col-xs-12">

				<div class="puzzle-title">
					<?php echo $title ?>
				</div>

				<div class="puzzle-description">
					<?php print($body_text) ?>
				</div>

			</div>

			<div class="content col-md-3 col-xs-12 centered">

				<div class="row">

					<?php if (!$printing && !$in_preview) { ?>

						<button class="puzzle-button light-blue"
								onclick="window.location = '/print' + window.location.pathname">
							Print
						</button>
						<button class="puzzle-button blue"
								onclick="window.location = '/printpdf' + window.location.pathname">
							PDF
						</button>
						<button class="puzzle-button light-blue" title="Restart Puzzle" onclick="location.reload()">
							&nbsp;<i class="fa fa-refresh"></i>&nbsp;
						</button>
						<button class="puzzle-button btn-volume blue" title="toggle volume" onclick="window.mute = !window.mute; window.playAudio('hover')">
							&nbsp;<i class="fa fa-volume-up"></i>&nbsp;
						</button>

						<div class="col-xs-12">
							<div class="addthis_inline_share_toolbox_m0wb"></div>
						</div>
					<?php } ?>


				</div>

			</div>

		</div>

	</div>

	<?php if (!$printing) { ?>

		<div class="section-border-container whitened">
			<div class="section-border">
				<div class="section-middle">
					<svg class="shadow" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">
						<path fill-rule="evenodd"
							  d="M1200.000,-0.000 C1200.000,-0.000 674.943,-0.000 645.000,-0.000 C615.057,-0.000 601.397,11.991 600.000,12.000 C598.603,12.009 585.000,-0.000 555.000,-0.000 C551.434,-0.000 -0.000,-0.000 -0.000,-0.000 L-0.000,11.960 C-0.000,11.960 525.000,11.960 555.000,11.960 C591.000,11.960 594.795,37.920 600.000,37.960 C605.205,38.000 609.000,11.960 645.000,11.960 C674.661,11.960 1200.000,11.960 1200.000,11.960 L1200.000,-0.000 Z"/>
					</svg>
				</div>
			</div>
		</div>

	<?php } ?>

	<div class="puzzle-page">

		<div class="container">

			<div class="content col-lg-6 col-md-12">

				<div class="puzzle-box-container">

					<div class="puzzle-box">

						<div id="crossword"></div>

					</div>

					<div style="clear:both"></div>

				</div>

			</div>

			<div class="content col-lg-6 col-md-12">

				<?php if (!$printing) { ?>

					<div class="centered padded">
						<?php if($in_preview) { ?>
							<div id="preview-form-replacement"></div>
						<?php } ?>

						<button class="puzzle-button light-blue" onclick="checkForErrors()">
							Check Puzzle
						</button>

					</div>

				<?php } ?>

				<div class="row padded">

					<div class="col-lg-12 col-md-6 col-xs-12">
						<h3 class="title">Across</h3>
						<ul id="across"></ul>
					</div>

					<div class="col-lg-12 col-md-6 col-xs-12">
						<h3 class="title">Down</h3>
						<ul id="down"></ul>
					</div>

					<?php if(!$field_disable_word_bank[0]['value']) { ?>
						<div class="col-xs-12">
							<h3 class="title">Word Bank</h3>
							<div id="words"></div>
						</div>
					<?php } ?>

				</div>

			</div>

		</div>

		<?php if($printing) { ?>
			<div class="container answer-key">

			<div class="content col-md-6 col-xs-12">

				<div class="puzzle-title">

					Answer Key

				</div>

			</div>
			<div class="col-md-12">
				<div class="puzzle-box-container">

					<div class="puzzle-box">

						<div id="crossword-answer-key"></div>

					</div>

					<div style="clear:both"></div>

				</div>
			</div>
		</div>
		<?php } ?>

	</div>

	<?php if (!$printing) { ?>

		<div class="modal fade puzzle-modal" tabindex="-1" role="dialog" id="puzzlemodal">
			<canvas id="confetti"
					style="position: absolute; width: 100%; height: 100%; background-color: transparent;"></canvas>
			<div class="modal-dialog modal-lg" role="document">
				<div class="modal-content">
					<div class="modal-header">
						<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span
								aria-hidden="true">&times;</span></button>
						<h4 class="modal-title">
                <img src="/sites/all/themes/custom/rif2018/build/img/logo-rif-lc.png">
						</h4>
					</div>
					<div class="section-border-container">
						<div class="section-border">
							<div class="section-left">
								<div class="line"></div>
							</div>
							<div class="section-middle">
								<svg class="shadow" xmlns="http://www.w3.org/2000/svg"
									 xmlns:xlink="http://www.w3.org/1999/xlink">
									<path fill-rule="evenodd"
										  d="M1200.000,-0.000 C1200.000,-0.000 674.943,-0.000 645.000,-0.000 C615.057,-0.000 601.397,11.991 600.000,12.000 C598.603,12.009 585.000,-0.000 555.000,-0.000 C551.434,-0.000 -0.000,-0.000 -0.000,-0.000 L-0.000,11.960 C-0.000,11.960 525.000,11.960 555.000,11.960 C591.000,11.960 594.795,37.920 600.000,37.960 C605.205,38.000 609.000,11.960 645.000,11.960 C674.661,11.960 1200.000,11.960 1200.000,11.960 L1200.000,-0.000 Z"/>
								</svg>
							</div>
							<div class="section-right">
								<div class="line"></div>
							</div>
						</div>
					</div>
					<div class="modal-body">
						<h2>Congratulations!</h2>
						<p>You've completed <?php echo $title ?>! Don't forget that you can save this game to your
							favorites, print it, or download it as a PDF.</p>
					</div>
					<div class="modal-footer">
						<button type="button" class="btn btn-warning" data-dismiss="modal">Close</button>
						<?php if(!$in_preview) { ?>
							<button type="button" class="btn btn-warning" onclick="location.reload()">Play Again</button>
						<?php } ?>
					</div>
				</div><!-- /.modal-content -->
			</div><!-- /.modal-dialog -->
		</div><!-- /.modal -->

	<?php } ?>

</div>

<script>
    jQuery(function() {
        rif.createCrosswordPuzzle({
            words:              <?php echo json_encode($def_words) ?>,
            clues:              <?php echo json_encode($def_clues) ?>,
            seed:               <?php echo json_encode($random_seed) ?>,
            printing:           <?=json_encode($printing)?>,
            activate:           true,
			showKey: 			true,
            puzzleElement:      document.getElementById('crossword'),
            keyElement:      	document.getElementById('crossword-answer-key'),
            downElement:        document.getElementById('down'),
            acrossElement:      document.getElementById('across'),
            modalElement:       document.getElementById('puzzlemodal'),
            wordsElement:       document.getElementById('words'),
            onNotEnoughWords: function() {
                jQuery('.puzzle-box-container').html(
                    '<div class="puzzle-box">' +
                    '<div id="crossword" class="no-solution">A Crossword needs at least 2 words.</div>' +
                    '</div>'
                );
				disableSave();
            },
            onBadWords: function() {
                jQuery('.puzzle-box-container').html(
                    'The following words could not be placed on the puzzle: ' + badwords.join(', ')
                );
				disableSave();
            },
            onCannotGenerate: function() {
                jQuery('.puzzle-box-container').html(
                    '<div class="puzzle-box">' +
                    '<div id="crossword" class="no-solution">A puzzle could not be generated with the given definitions.</div>' +
                    '</div>'
                );
				disableSave();
            }
        });
    });
</script>
