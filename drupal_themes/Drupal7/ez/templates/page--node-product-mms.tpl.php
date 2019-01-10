<div id="landing" class="landing-mms <?php print $classes; ?>"<?php print $attributes; ?>>

  <!-- ______________________ HEADER _______________________ -->


  <?php if ($page['header']): ?>
      <?php print render($page['header']); ?>
  <?php endif; ?>



  <!-- ______________________ MAIN _______________________ -->

  <div class="hero">

    <?php
      include "./".path_to_theme()."/includes/header-landing.inc";
    ?>

    <div class="container">
      <div class="row">
        <div class="col-md-6 col-md-offset-6">
          <h1 class="title"><span class="introducing">Introducing</span> <?php print $title; ?><br> <span class="by-line">by EZ Texting</span></h1>
          <p class="intro">Send pictures, video and more with MMS (Multimedia Messaging Service) by Ez Texting.<sup>*</sup></p>
          <a class="btn btn-green btn-lg" role="button" href="/start">Get Started for Free</a>
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