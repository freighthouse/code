<div id="landing" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <!-- ______________________ HEADER _______________________ -->



  <div class="navbar navbar-default" role="navigation">
    <div class="container">
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="navbar-brand">
        <img src="<?php print base_path() . path_to_theme() . "/images/ez-texting-logo-white.png"; ?>" alt="<?php print t('Home'); ?>">
      </a>
      <ul class="nav navbar-nav navbar-right">
        <li class="phone-number">Se Habla Espa&ntilde;ol <a href="tel:+18668679273">(866) 867-9273</a></li>
      </ul>
    </div>
  </div>


  <?php if ($page['header']): ?>
      <?php print render($page['header']); ?>
  <?php endif; ?>



  <!-- ______________________ MAIN _______________________ -->

  <div class="hero">
    <div class="container">
      <h1 class="title"><?php print $title; ?></h1>
      <h2><?php print get_node_field($node, 'field_subtitle'); ?></h2>
      <p><a class="btn btn-green btn-lg" role="button" href="/start">Get Started for Free</a></p>
      <p>No Credit Card · No Obligation · No Setup Fees</p>
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