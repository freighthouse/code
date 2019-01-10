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
$words = preg_split("/[\s,]+/", $words);
$printing = substr($_SERVER['REQUEST_URI'], 0, 6) === '/print';
$animate = true;
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

	#puzzle table {
		width: 100%;
	}

	#puzzle table td {
		padding: 1em;
		text-align: center;
		vertical-align: middle;
	}

	#puzzle .front,
	#puzzle .back,
	#puzzle .card {
		width: 95%;
		height: 140px;
		font-weight: bold;
	}

	#puzzle .card {
		cursor: pointer;
		-webkit-user-select: none;
		-moz-user-select: none;
		-ms-user-select: none;
		user-select: none;
		margin: 10px;
		font-size: 24px;
		/* Animation */
		perspective: 1000px;
		transform-style: preserve-3d;
	}

	#puzzle .card.for-print {
		float: left;
		width: 200px;
		margin: 28px;
	}

	#puzzle .card .front {
		border-radius: 1em;
		color: #0079c1;
		border: 8px solid #0079c1;
		background-color: white;
		background-image: none;
		font-size: 1.5em;
		text-align: center;
		line-height: 130px;
		white-space: nowrap;
		overflow: hidden;
		/* Animation */
		z-index: 2;
		transform: rotateY(0deg);
	}

	#puzzle .card .back {
		border-radius: 1em;
		background-color: #0079c1;

		/* PATTERN  */
		background-image: url(/sites/all/themes/custom/rif/public/assets/images/puzzles/card.png);
		background-repeat: repeat;
		/**/

		/* RIF LOGO * /
		background-image: url(/sites/all/themes/custom/rif/public/assets/images/rif-logo-mark.png);
		background-repeat: no-repeat;
		background-position: 50%;
		background-size: 80%;
		/**/

		/* Animation */
		transform: rotateY(-180deg);
	}

	#puzzle .card.flipped .back {
		transform: rotateY(0deg);
	}

	#puzzle .card.flipped .front {
		transform: rotateY(180deg);
	}

	#puzzle .flipper {
	<?php if ($animate) { ?> transition: 0.6s;
	<?php } ?> transform-style: preserve-3d;
		position: relative;
	}

	#puzzle .front,
	#puzzle .back {
		backface-visibility: hidden;
	<?php if ($animate) { ?> transition: 0.6s;
	<?php } ?> transform-style: preserve-3d;
		position: absolute;
		top: 0;
		left: 0;
	}

	#puzzle .card.done {
		cursor: inherit;
	}

	#puzzle .card.done .front {
		border: 8px solid #a6ce39;
	}

	#puzzle table tbody {
		border-top: none;
	}

	.puzzle-page .clear {
		clear: both;
	}

	<?php if ($printing) { ?>
	img.print-logo {
		-webkit-filter: grayscale(100%);
		filter: grayscale(100%);
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
	}
	#puzzle {
		display: none;
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

	<?php } ?>
</style>

<script>

var REFLIP_WAIT_TIME = 1000;
var words = <?php echo json_encode($words) ?>;
var printing = <?php echo json_encode($printing) ?>;
var chooseWords = <?php echo json_encode(intval($choose_words)) ?>;
var alternateCase = <?php echo json_encode(intval($alternate_case)) ?>;
var previousCard = null;
var lastCard = null;
var cardsFlipped = 0;
var pairsFound = 0;

// Uncomment this section of code if we want to print all of the matching words not just the number of words to chose
//if (printing) {
//    chooseWords = words.length;
//}

jQuery('img.print-logo').prop('src', '/sites/all/themes/custom/rif2018/build/img/logo-rif-lg.png');

window.onload = function()
{
    Math.seedrandom(<?php echo json_encode($random_seed) ?>);

    var n = chooseWords;
	var chosenWords = [];
    var chosenAlternated = [];

    for (var i = 0; i < chooseWords; i++) {
        var k = Math.floor(Math.random() * words.length);
        chosenWords.push( words[ k ] );
        chosenAlternated.push( 0 );
        words.splice( k, 1 );
    }
    
    function getWordAt(i) {
        var word = chosenWords[i];
        if (alternateCase && word) {
            if (chosenAlternated[i] % 2 == 0) {
                word = word.toLowerCase();
            } else {
                word = word.substring(0, 1).toUpperCase() + word.substring(1).toLowerCase();
            }
            chosenAlternated[i]++;
        }
        return word;
    }

    if(printing) {
    	//Replace Word cut out div with words
		var $wordLists = jQuery('#word-cut-outs');
		jQuery.each(chosenWords, function(i, currWord){
			var $currRow = jQuery('<tr class="word-list-row word-list-row-'+i+'"></tr>').appendTo($wordLists);
            var tdClass = alternateCase ? '' : ' non-alternating';
			$currRow
                .append('<td class="word-card' + tdClass + '"><div class="word">'+getWordAt(i)+'</div></td>')
                .append('<td class="word-card' + tdClass + '"><div class="word">'+getWordAt(i)+'</div></td>')
            ;
		});
	}

    var columnsMedium = getColumnsMedium( n * 2 );
    var columnsSmall = getColumnsSmall( n * 2 );
    var swaps = n * 3;
    var puzzleElement = document.getElementById('puzzle');

    var placement = new Array( n * 2 );
    for (var i = 0; i < n; i++) {
        placement[ i ] = i;
        placement[ i + n ] = i;
    }

    for (var i = 0; i < swaps; i++) {
        var j = Math.floor( Math.random() * placement.length );
        var k = Math.floor( Math.random() * placement.length );
        var temp = placement[ j ];
        placement[ j ] = placement[ k ];
        placement[ k ] = temp;
    }

    var html = [];
    html.push('<div class="row">');

    for (var i = 0; i < placement.length; i++) {
        var wordIndex = placement[ i ];
        var word = getWordAt(wordIndex);
        var classes = printing ? 'card for-print' : 'card flipped';

        html.push('<div class="col-md-' + columnsMedium + ' col-sm-' + columnsSmall + ' col-xs-6"><div data-word="' + wordIndex + '" class="' + classes + '" onclick="onCardClick(event, this)"><div class="flipper"><div class="front">' + word + '</div><div class="back"></div></div></div></div>');
    }

    html.push('</div>');

    puzzleElement.innerHTML = html.join("\n");

    iterate('.card', function(card)
    {
        var onTransitionEnd = function()
        {
            if (card === lastCard && cardsFlipped === 2)
            {
                var word1 = lastCard.getAttribute('data-word');
                var word2 = previousCard.getAttribute('data-word');

                if (word1 === word2)
                {
                    lastCard.classList.add('done');
                    previousCard.classList.add('done');

                    previousCard = null;
                    lastCard = null;
                    cardsFlipped = 0;
                    pairsFound++;

                    if (pairsFound === chosenWords.length)
                    {
                        playAudio('good');

                        var modal = jQuery('#puzzlemodal').modal();
                        var conf = null;

                        modal.one('shown.bs.modal', function() {
                            conf = new confetti.Context('confetti');
                            conf.start();
                            window.addEventListener('resize', function(event){
                              conf.resize();
                            });
                        });

                        modal.one('hidden.bs.modal', function() {
                            conf.stop();
                        });
                    }
                    else
                    {
                        playAudio('boop-calm');
                    }
                }
                else
                {
                    playAudio('bad', 0.1);

                    setTimeout(function()
                    {
                        card.classList.add('flipped');
                        if (previousCard) {
                            previousCard.classList.add('flipped');
                        }

                        previousCard = null;
                        lastCard = null;
                        cardsFlipped = 0;

                    }, REFLIP_WAIT_TIME);
                }
            }
        }

<?php if ($animate) { ?>
        onEvent(card.firstElementChild, 'TransitionEnd', onTransitionEnd);
<?php } else { ?>
        jQuery( card ).on( 'evaluate', onTransitionEnd );
<?php } ?>

    });
};

function getColumnsMedium(wordCount)
{
    if (wordCount % 4 === 0)
    {
        return 3;
    }
    if (wordCount % 3 === 0)
    {
        return 4;
    }

    return 3;
}

function getColumnsSmall(wordCount)
{
    return 4;
}

function onCardClick(e, card)
{
    if (card.classList.contains('done'))
    {
        return;
    }

    playAudio('hover');

    switch (cardsFlipped)
    {
    case 0:
        card.classList.remove('flipped');
        previousCard = card;
        cardsFlipped = 1;
        break;
    case 1:
        if (previousCard === card) {
            card.classList.add('flipped');
            previousCard = null;
            cardsFlipped = 0;
        } else {
            card.classList.remove('flipped');
            lastCard = card;
            cardsFlipped = 2;
<?php if (!$animate) { ?>
            jQuery( card ).trigger( 'evaluate' );
<?php } ?>
        }
        break;
    }
}

var prefixes = ["webkit", "moz", "MS", "o", ""];

function onEvent(element, type, callback)
{
	for (var p = 0; p < prefixes.length; p++)
    {
		if (!prefixes[p]) type = type.toLowerCase();

		element.addEventListener(prefixes[p] + type, callback, false);
	}
}

function iterate(selector, func)
{
    var nodes = document.querySelectorAll(selector);

    for (var i = 0; i < nodes.length; i++)
    {
        var node = nodes.item(i);

        if (func( node, i ) === false)
        {
            break;
        }
    }

    return nodes;
}

jQuery(function()
{
    var a = jQuery('.print-site_name');
    var b = jQuery('.print-breadcrumb');
    a.remove();
    b.remove();
});

</script>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

<div class="puzzle-header-row">

    <div class="container">

        <div class="content col-md-3 col-xs-12 centered">

        <?php if (!$printing) { ?>

            <img src="/sites/all/themes/custom/rif/public/assets/images/puzzles/icon_puzzle.png">

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
                    <button class="puzzle-button btn-volume blue" title="toggle volume" onclick="window.mute = !window.mute; window.playAudio('hover')">
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
		<?php if($in_preview) { ?>
			<div class="col-xs-12 centered">
				<div id="preview-form-replacement"></div>
			</div>
		<?php } ?>

        <div id="puzzle"></div>
		<?php if($printing) {?>
			<div class="printing-puzzle">
				<table id="word-cut-outs"></table>
			</div>
		<?php } ?>


        <div class="clear"></div>

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
