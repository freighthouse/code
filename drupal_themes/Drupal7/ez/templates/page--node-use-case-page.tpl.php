<div id="page" class="page-interior use-case-page <?php print $classes; ?>"<?php print $attributes; ?>>

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
        <a class="btn btn-lg btn-orange" href="/start">Get Started Now</a>
      </div>
    </div>


    <div class="container" id="content">

      <?php if ($messages || $tabs || $action_links): ?>
        <div id="content-header" class="row">

          <?php if ($page['highlight']): ?>
            <div id="highlight"><?php print render($page['highlight']) ?></div>
          <?php endif; ?>

          <?php print render($title_suffix); ?>
          <?php print $messages; ?>
          <?php print render($page['help']); ?>

          <?php if ($tabs): ?>
            <?php print render($tabs); ?>
          <?php endif; ?>

          <?php if ($action_links): ?>
            <ul class="action-links"><?php print render($action_links); ?></ul>
          <?php endif; ?>

        </div> <!-- /#content-header -->
      <?php endif; ?>

      <div class="row">
        <?php if ($page['sidebar_first']) { ?>
          <div class="col-sm-3 sidebar">
            <?php print render($page['sidebar_first']); ?>
            <?php print render($page['sidebar_bottom']); ?>
          </div>
          <div class="col-sm-9 content">
            <?php print render($page['content']) ?>
          </div>
        <?php } else { ?> <!-- /sidebar-first -->
          <div class="col-sm-12 content">
            <?php print render($page['content']) ?>
            <div class="cta">
              <a href="/start" class="btn btn-lg btn-orange">Get Started Now</a>
            </div>
          </div>
        <?php } ?>
      </div>
      <?php if ($page['content_bottom']) { ?>
        <div class="row">
          <?php print render($page['content_bottom']) ?>
        </div>
      <?php } ?>
    </div>

    <!-- ______________________ FOOTER _______________________ -->

    <?php
      include "./".path_to_theme()."/includes/footer.inc";
    ?>

  </section>

</div> <!-- /page -->
<?php print render($page['footer']) ?>