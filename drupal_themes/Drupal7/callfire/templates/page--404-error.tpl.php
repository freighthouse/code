<div id="page">
	<header id="header" class="clearfix" role="banner">
		<div id="sales-number"><i class="icon-tiny-phone"> </i> Call Us!&nbsp;&nbsp;<span>(877) 897-FIRE</span></div>

		<?php print render($page['header']); ?>
	</header>

	<div id="main">
  	<?php print render($page['content_top']); ?>

      <div id="four-oh-four">
  	    <div id="content" role="main">
  	      <a id="main-content"></a>
  		      <?php print render($tabs); ?>
  		      <?php print render($page['content']); ?>
  	    </div><!-- /#content -->
      </div><!-- /#four-oh-four -->
      <div id="four-oh-four-identifier">Aren't you glad we didn't call it a <a href="http://en.wikipedia.org/wiki/HTTP_404" target="_blank">404</a> page?</div>
    
  </div><!-- /#main -->  

</div><!-- /#page -->