<div id="page" class="page-404 page <?php print $classes; ?>"<?php print $attributes; ?>>

  <!-- ______________________ HEADER _______________________ -->


  <div class="navbar navbar-default" role="navigation">
    <div class="container">
      <div class="navbar-header">
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="navbar-brand">
            <img src="<?php print base_path() . path_to_theme() . "/images/ez-texting-logo-white.png"; ?>" alt="<?php print t('Home'); ?>">
          </a>
        </div>
      <ul class="nav navbar-nav navbar-right">
        <li class="phone-number">Call now! <a href="tel:+18007535732">(800) 753-5732</a></li>
        <li><a class="btn btn-rounded btn-orange" href="https://app.eztexting.com">Log In</a></li>
      </ul>
    </div>
  </div>

  <?php if ($page['header']): ?>
      <?php print render($page['header']); ?>
  <?php endif; ?>

  <section class="content-wrap slide" id="main">

  <!-- ______________________ MAIN _______________________ -->

    <div class="container" id="content">
      <div class="text-body">
        <?php print render($page['content']) ?>
      </div>
      <div class="sender">
        <p>404</p>
        <div class="pull-right time">
          Today <?php echo date("g:i a"); ?>
        </div>
      </div>
      <div class="row">
        <div class="col-sm-3">
          <h3>Ez Texting</h3>
          <?php print theme('links', array('links' => menu_navigation_links('main-menu')));?>
          <ul>
        </div>
        <div class="col-sm-3">
          <h3>About</h3>
          <?php print theme('links', array('links' => menu_navigation_links('menu-about')));?>
        </div>
        <div class="col-sm-3">
          <h3>Resources</h3>
          <?php print theme('links', array('links' => menu_navigation_links('menu-resources')));?>
        </div>
        <div class="col-sm-3">
          <h3>Help / Contact</h3>
          <?php print theme('links', array('links' => menu_navigation_links('menu-help-contact')));?>
        </div>
      </div>
    </div>

    <!-- ______________________ FOOTER _______________________ -->

  </section>

</div> <!-- /page -->
<?php print render($page['footer']) ?>