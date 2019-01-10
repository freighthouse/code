<div id="landing" class="<?php print $classes; ?> landing-alt"<?php print $attributes; ?>>

  <!-- ______________________ HEADER _______________________ -->


  <?php if ($page['header']): ?>
      <?php print render($page['header']); ?>
  <?php endif; ?>



  <!-- ______________________ MAIN _______________________ -->

  <div class="hero">
    <div class="phone"></div>
    <div class="container">
      <div class="row">
        <div class="col-md-7 col-md-offset-5">
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="brand">
            <img src="<?php print base_path() . path_to_theme() . "/images/ez-texting-logo-landing.png"; ?>" alt="<?php print t('Home'); ?>">
          </a>
          <?php
            print get_node_field($node, 'body', 'teaser');
          ?>
          <div class="sign-up">
            <a class="btn btn-green btn-lg" role="button" href="/start">Get Started for Free</a>
            <div>No Credit Card &bull; No Obligation &bull; No Setup Fees</div>
          </div>
        </div>
      </div>
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
    include "./".path_to_theme()."/includes/footer-landing.inc";
  ?>

</div> <!-- /page -->
<?php print render($page['footer']) ?>