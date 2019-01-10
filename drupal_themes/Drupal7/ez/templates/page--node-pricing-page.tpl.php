<div id="pricing" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <!-- ______________________ HEADER _______________________ -->



  <?php
    include "./".path_to_theme()."/includes/header.inc";
  ?>  

    

  <?php if ($page['header']): ?>
      <?php print render($page['header']); ?>
  <?php endif; ?>

  <section class="content-wrap slide" id="main">

    <!-- ______________________ MAIN _______________________ -->

    <div class="hero-int">
      <div class="container">
        <h1 class="title"><?php print $title; ?></h1>
        <?php if (get_node_field($node, 'field_subtitle')) { ?>
          <h2>[ <?php print get_node_field($node, 'field_subtitle'); ?> ]</h2>
        <?php } ?>
      </div>
    </div>

    <?php if ($messages || $tabs || $action_links): ?>
    <div class="container">
      <div id="content-header" class="row">

        <?php if ($page['highlight']): ?>
          <div id="highlight"><?php print render($page['highlight']) ?></div>
        <?php endif; ?>

        <?php print render($title_suffix); ?>
        <?php print $messages; ?>
        <?php print render($page['help']); ?>

        <?php if ($tabs): ?>
          <div class="tabs"><?php print render($tabs); ?></div>
        <?php endif; ?>

        <?php if ($action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
        
      </div> <!-- /#content-header -->
    </div>
    <?php endif; ?>
    
    <div class="content">
      <?php print render($page['content']) ?>
      <?php print render($page['content_bottom']) ?>
    </div>

    <!-- ______________________ FOOTER _______________________ -->

    <?php
      include "./".path_to_theme()."/includes/footer.inc";
    ?>  

  </section>

</div> <!-- /page -->
<?php print render($page['footer']) ?>