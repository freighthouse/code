<div id="page">
	<header id="header" class="clearfix" role="banner">
		<div id="sales-number"><i class="icon-tiny-phone"> </i> Call Us!&nbsp;&nbsp;<span>(877) 897-FIRE</span></div>

		<?php print render($page['header']); ?>
	</header>

	<div id="main">
  	<?php print render($page['content_top']); ?>

    <?php
      $field = field_get_items('node', $node, 'field_case_study_image');
      $output = field_view_value('node', $node, 'field_case_study_image', $field[0], array(
        'type' => 'image'
      ));
      $big_image = render($output);

      $field = field_get_items('node', $node, 'field_tag_line');
      $output = field_view_value('node', $node, 'field_tag_line', $field[0]);
      $tag_line = $output['#markup'];

      $field = field_get_items('node', $node, 'field_client_logo');
      $output = field_view_value('node', $node, 'field_client_logo', $field[0], array(
        'type' => 'image'
      ));
      $client_logo = render($output);

      $field = field_get_items('node', $node, 'field_sidebar');
      $output = field_view_value('node', $node, 'field_sidebar', $field[0]);
      $sidebar_content = $output['#markup'];

      $field = field_get_items('node', $node, 'field_case_study_link');
      $output = field_view_value('node', $node, 'field_case_study_link', $field[0]);
      $case_study_link = $output['#markup'];
    ?>

    <div id="case-study-header">
      <?php print $big_image; ?>
      <h1 class="title" id="page-title"><span>Case Study</span><br><?php print $title;?></h1>
    </div>

    <div class="all-content clearfix mini-grid">

      <div class="grid-12">
        <p class="tag-line"><?php print $tag_line;?></p>
      </div>

	    <div id="content" class="grid-9" role="main">
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

      <aside class="sidebar grid-3">
        <?php print $client_logo; ?>
        <?php print $sidebar_content; ?>
        <a class="button" href="<?php print $case_study_link; ?>">Download Case Study PDF</a>
      </aside><!-- /.sidebar -->

    </div><!-- /#all-content -->

    <?php print render($page['content_bottom']); ?>
    
  </div><!-- /#main -->  

  <?php print render($page['footer_links']); ?>
  <?php print render($page['footer']); ?>

</div><!-- /#page -->