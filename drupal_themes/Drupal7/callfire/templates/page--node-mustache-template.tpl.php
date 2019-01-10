<div id="page">
	<header id="header" class="clearfix" role="banner">
		<div id="sales-number"><i class="icon-tiny-phone"> </i> Call Us!&nbsp;&nbsp;<span>(877) 897-FIRE</span></div>

		<?php print render($page['header']); ?>
	</header>

	<div id="main">
  	<?php print render($page['content_top']); ?>

	<?php
      // Render the sidebars to see if there's anything in them.
      $sidebar_first  = render($page['sidebar_first']);
      $sidebar_second = render($page['sidebar_second']);
      $sidebar_present = false;
      if ($sidebar_first) { 
          $content_width = '-9';
          $sidebar_present = true;
      }
      else if ($sidebar_second) {
          $sidebar_present = true;
          $content_width = '-8';
      }
      else {
          $content_width = '';
      }
    ?>

    <div class="all-content clearfix mini-grid">

        <?php if ($sidebar_first): ?>
            <aside class="sidebar grid-3">
                <?php print $sidebar_first; ?>
            </aside><!-- /.sidebar -->
        <?php endif; ?>

    
	    <div id="content" class="grid<?php echo $content_width; ?>" role="main">
	      <a id="main-content"></a>
		      <?php print render($title_prefix); ?>
		      <?php print render($title_suffix); ?>
		      <?php print $messages; ?>
		      <?php print render($tabs); ?>
		      <?php print render($page['help']); ?>
		      <?php if ($action_links): ?>
		        <ul class="action-links"><?php print render($action_links); ?></ul>
		      <?php endif; ?>
		      <?php print render($page['content']); ?>

	        <?php print $feed_icons; ?>
	    </div><!-- /#content -->

	    <?php if ($sidebar_second): ?>
        <aside class="sidebar grid-4">
          <?php print $sidebar_second; ?>
        </aside><!-- /.sidebar -->
      <?php endif; ?>

    </div><!-- /#all-content -->

    <?php print render($page['content_bottom']); ?>
    
  </div><!-- /#main -->  

  <?php print render($page['footer_links']); ?>
  <?php print render($page['footer']); ?>

</div><!-- /#page -->
