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
$words = explode("\n", $words);
$words = array_map('trim', $words);
$words = array_map('strtoupper', $words);
$printing = substr($_SERVER['REQUEST_URI'], 0, 6) === '/print';
?>

<!-- VERY crude implementation. The CSS should be moved out ideally - perhaps even the javascript. There's some inline styling here that should be cleaned up. -->

<style type="text/css">
.puzzle-well {
    background-color: #ffffff;
    margin-top: 2em
}
.puzzle-actions {
    text-align: right;
}
.puzzle-container {
    text-align: center;
}

.puzzle-to-draw div {
  width: 100%;
  margin: 0 auto;
}

.puzzle-to-draw button::-moz-focus-inner {
  border: 0;
}

.puzzle-to-draw button:focus {
    outline: none;
}

.puzzle-to-draw .puzzleSquare {
  color: black;
  height: 30px;
  width: 30px;
  text-transform: uppercase;
  background-color: white;
  border: 0;
  font: 1em sans-serif;
}

.puzzle-to-draw .selected {
  background-color: #ffa585 !important;
}
.puzzle-to-draw .found {
  background-color: #c9e109;
}
.puzzle-to-draw .solved {
  background-color: #a6ce39;
  color: white;
}
.puzzle-to-draw .complete {
  background-color: #a6ce39;
}
.puzzle-to-draw .puzzleRow {
    white-space: nowrap;
}

#words {
    margin-top: 0;
    padding-top: 0;
}
#words .word.wordFound {
    color: #aaa;
    background-color: #ddd;
}
.clear {
    clear: both;
}
<?php if (!$printing) { ?>
#words .word {
    border-radius: 8px;
    text-align: center;
    background-color: #146da8;
    text-transform: uppercase;
    font-weight: bold;
    padding: 12px 6px;
    margin: 6px;
}
<?php } else { ?>
#words .word {
    width: 33.333%;
    float: left;
    text-align: center;
    padding: 10px 0;
    font-weight: bold;
}
#words {
    margin-bottom: 60px;
}
img.print-logo {
    -webkit-filter:  grayscale(100%);
    filter:  grayscale(100%);
    width: 300px;
}
.puzzle-title {
    font-size: 24px;
    text-align: center;
    font-weight: bold;
	margin-bottom: 15px;
}
.puzzle-description {
    font-size: 18px;
    text-align: center;
    display: block;
	margin-bottom: 15px;
}
html, body {
	width: 100%;
	height: 100%;
	margin-left: 0 !important;
	margin-right: 0 !important;
}
@page {
	size: letter;
	margin: .5in;
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
	overflow: hidden;
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

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

<div class="puzzle-header-row">

    <div class="container">

        <div class="content col-md-3 col-xs-12 centered">

        <?php if (!$printing) { ?>

            <img src="/sites/all/themes/custom/rif/public/assets/images/puzzles/icon_wordsearch.png">

        <?php } ?>

        </div>

        <div class="content col-md-6 col-xs-12">

            <div class="puzzle-title">
                <?php echo $title ?>
            </div>

            <div class="puzzle-description">
                <?php print( $body_text ) ?>
            </div>

        </div>

        <div class="content col-md-3 col-xs-12 centered">

            <div class="row">

            <?php if (!$printing && !$in_preview) { ?>

                <div class="col-xs-12">
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
                    <button title="toggle volume" class="puzzle-button btn-volume blue" onclick="window.mute = !window.mute; window.playAudio('hover')">
                        &nbsp;<i class="fa fa-volume-up"></i>&nbsp;
                    </button>
                </div>

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
          <path fill-rule="evenodd" d="M1200.000,-0.000 C1200.000,-0.000 674.943,-0.000 645.000,-0.000 C615.057,-0.000 601.397,11.991 600.000,12.000 C598.603,12.009 585.000,-0.000 555.000,-0.000 C551.434,-0.000 -0.000,-0.000 -0.000,-0.000 L-0.000,11.960 C-0.000,11.960 525.000,11.960 555.000,11.960 C591.000,11.960 594.795,37.920 600.000,37.960 C605.205,38.000 609.000,11.960 645.000,11.960 C674.661,11.960 1200.000,11.960 1200.000,11.960 L1200.000,-0.000 Z"/>
        </svg>
      </div>
    </div>
</div>

<?php } ?>

<div class="puzzle-page">

    <div class="container">

        <div class="content col-lg-6 col-md-12">

            <div class="puzzle-box-container">

			<?php if ($printing) { ?>

				<div class="puzzle-box word-search">

                  <div id="puzzle" class="puzzle-to-draw"></div>

                </div>
                
			<?php } else { ?>

                <div class="puzzle-box">

                    <div id="puzzle" class="puzzle-to-draw"></div>

                </div>

			<?php } ?>

                <div style="clear: both"></div>

            </div>

        </div>

        <div class="content col-lg-6 col-md-12 centered">

			<?php if($in_preview) { ?>
				<div id="preview-form-replacement"></div>
			<?php } ?>

			<h3 class="centered title">Word Bank</h3>

            <div id="words" class="row padded"></div>

            <div style="clear: both"></div>

        </div>

		<?php if ($printing) { ?>
            
			<div class="container answer-key">
				<div class="content col-md-6 col-xs-12">

					<div class="puzzle-title">
						Answer Key
					</div>

					<div class="content col-xs-12">

						<div class="puzzle-box-container">

							<div class="puzzle-box word-search">

								<div id="answers" class="puzzle-to-draw"></div>

							</div>

						</div>

					</div>
				</div>
			</div>
            
		<?php }?>

    </div>

</div>

<?php if (!$printing) { ?>

    <div class="modal fade puzzle-modal" tabindex="-1" role="dialog" id="puzzlemodal">
      <canvas id="confetti" style="position: absolute; width: 100%; height: 100%; background-color: transparent;"></canvas>
      <div class="modal-dialog modal-lg" role="document">
        <div class="modal-content">
          <div class="modal-header">
            <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
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
                  <svg class="shadow" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">
                    <path fill-rule="evenodd" d="M1200.000,-0.000 C1200.000,-0.000 674.943,-0.000 645.000,-0.000 C615.057,-0.000 601.397,11.991 600.000,12.000 C598.603,12.009 585.000,-0.000 555.000,-0.000 C551.434,-0.000 -0.000,-0.000 -0.000,-0.000 L-0.000,11.960 C-0.000,11.960 525.000,11.960 555.000,11.960 C591.000,11.960 594.795,37.920 600.000,37.960 C605.205,38.000 609.000,11.960 645.000,11.960 C674.661,11.960 1200.000,11.960 1200.000,11.960 L1200.000,-0.000 Z"/>
                  </svg>
                </div>
                <div class="section-right">
                  <div class="line"></div>
                </div>
              </div>
          </div>
          <div class="modal-body">
              <h2>Congratulations!</h2>
              <p>You've completed <?php echo $title ?>! Don't forget that you can save this game to your favorites, print it, or download it as a PDF.</p>
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

<?php
	$debug_value = json_encode($orientations);
?>

<script>
    jQuery(function() {

        rif.createWordfindPuzzle({
			words:              <?php echo json_encode($words) ?>,
			printing:           <?php echo json_encode($printing) ?>,
			width:              <?php echo json_encode($width) ?>,
			height:             <?php echo json_encode($height) ?>,
			orientations:       <?php echo json_encode($orientations) ?>,
			seed:               <?php echo json_encode($random_seed) ?>,
            activate:           true,
            puzzleElement:      document.getElementById('puzzle'),
            keyElement:      	document.getElementById('answers'),
            wordsElement:       document.getElementById('words'),
            modalElement:       document.getElementById('puzzlemodal'),
			onWordsOutOfBounds: function(shortWords, longWords) {
            	var message = "<p class='text-left'>Words must be at least two characters (and no more than 15). The following does not meet these requirements. Press the Edit button to adjust your puzzle.</p><ul class='text-left'><li>";
				var badWords = shortWords.concat(longWords);
            	if(badWords.length) {
					message += badWords.join('</li><li>');
				}
				message += "</li></ul>";
				jQuery('.puzzle-box-container').html(
					'<div class="puzzle-box"><div id="crossword" class="no-solution">' +
					message +
					'</div></div>'
				);
				disableSave();
			}
        });

    });
</script>
