<div id="page" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <!-- ______________________ HEADER _______________________ -->

  <?php
    include "./".path_to_theme()."/includes/header.inc";
  ?>

  <?php if ($page['header']): ?>
      <?php print render($page['header']); ?>
  <?php endif; ?>

  <div id="main" class="slide">

    <!-- ______________________ MAIN _______________________ -->

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

    <?php print render($page['content']) ?>

    <?php print render($page['content_bottom']) ?>

    <?php
    include "./".path_to_theme()."/includes/footer.inc";
  ?>

  </div> <!-- #content -->

</div> <!-- /page -->
<?php print render($page['footer']) ?>
