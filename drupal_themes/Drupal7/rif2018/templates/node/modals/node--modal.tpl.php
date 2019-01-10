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
	/** var states = //echo json_encode($states)*/

?>

	<?php 
	if ($show_trigger_button) { ?>
	    <button id="launch-modal-<?php echo $node->nid; ?>" type="button" data-toggle="modal" data-target="#modal-<?php echo $node->nid; ?>" class="btn btn-warning">Modal Open</button>
	<?php } ?>

	<?php 
	if ($show_trigger_button) { ?>
   		 <div class="modal fade" tabindex="-1" role="dialog" id="modal-<?php echo $node->nid; ?>">
	<?php } else { ?>
	    <div class="modal fade" tabindex="-1" role="dialog" id="modal-<?php echo $modal_trigger_target; ?>">
	<?php } ?>
      <div class="modal-dialog modal-lg" role="document">
        <div class="modal-content">
          <div class="modal-header">
            <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
            <h4 class="modal-title">
            	<img src="/sites/all/themes/custom/rif2018/build/img/logo-rif-lg.png" />
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
			<?php echo $body; ?>
          </div>
          <div class="modal-footer">
          	<?php if ($show_confirm_button) { ?>
   		    	<a
            		type="button" id="modal-confirm-<?php echo $node->nid; ?>"
            		class="btn btn-yellow-rif blue-border"
            	>
            		<?php echo $confirm_button_text; ?>
            	</a>
           	<?php } ?>
          </div>
        </div><!-- /.modal-content -->
      </div><!-- /.modal-dialog -->
    </div><!-- /.modal -->

<script>

(function($, global) {
<?php  if (!$show_trigger_button && !$bypass_modal) { ?>
		var modal = $('#modal-<?php echo ($modal_trigger_target) ?>');
		
		var toggleLink = $('#<?php echo ($modal_trigger_target) ?> > a');
		if (toggleLink) {
			toggleLink.attr('data-toggle', 'modal');
			toggleLink.attr('data-target', '#modal-<?php echo ($modal_trigger_target) ?>');
			var link = toggleLink.attr('href');
			toggleLink.attr('href', '#<?php echo $node->nid; ?>');
			toggleLink.click(function() {
				console.log(link);
				console.log('toggle link clicked');
				<?php if($track_views) { ?>
					var views = parseInt(getCookie("<?php echo $modal_trigger_target; ?>-views"));
					if(isNaN(views)) { views = 0; }
					document.cookie = "<?php echo $modal_trigger_target; ?>-views="+ (views+1);
				<?php } ?>
			});

			var extLinkBtn = $('#modal-confirm-<?php echo $node->nid; ?>');

			extLinkBtn.click(function() {
				console.log('confirmed link clicked');
				window.location.href = link
			});

			modal.find('.close').on('click', function() {
				var src = modal.find('iframe').attr('src');
    	        modal.find('iframe').attr('src', '');
        	    modal.find('iframe').attr('src', src);
        	});



		} else {
			var togglebutton = $('#<?php echo ($modal_trigger_target) ?>');
			togglebutton.attr('data-toggle', 'modal');
			togglebutton.attr('data-target', '#modal-<?php echo ($modal_trigger_target) ?>');
			togglebutton.click(function() {
				console.log('toggle button clicked');
			});
		}
<?php } ?>

	function getCookie(cname) {
		var name = cname + "=";
		var decodedCookie = decodeURIComponent(document.cookie);
		var ca = decodedCookie.split(';');
		for(var i = 0; i <ca.length; i++) {
			var c = ca[i];
			while (c.charAt(0) == ' ') {
				c = c.substring(1);
			}
			if (c.indexOf(name) == 0) {
				return c.substring(name.length, c.length);
			}
		}
		return "";
	}

})(jQuery, this );

</script>

