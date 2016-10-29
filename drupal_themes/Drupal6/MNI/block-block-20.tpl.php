<div class="side-box">
	<div class="facebook-area">
		<?php if (!empty($block->subject)): ?>
			<h3><?php print $block->subject ?> <a href="#"><img src="<?php print template_path; ?>/images/icon-facebook2.gif" alt="image description" /></a></h3>
		<?php endif;?>
		<?php print $block->content ?>
	</div>
</div>
