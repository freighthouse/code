<div class="navbar navbar-default navbar-fixed-top" role="navigation">
    <div class="container">
        <div class="navbar-header slide">
            <a href="#"  id="navToggle" class="slide">
                <i class="fa fa-bars"></i> MENU
            </a>
            <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="navbar-brand"><img src="<?php print base_path() . path_to_theme() . "/images/ez-texting-logo-white.png"; ?>" alt="<?php print t('Home'); ?>"></a>
        </div>
        <div class="navbar-trunk slide">
          <?php print theme('links', array('links' => $main_menu, 'attributes' => array('id' => 'primary', 'class' => array('links', 'clearfix', 'nav navbar-nav')))); ?>
            <ul class="nav navbar-nav navbar-right">
                <li class="phone-number"><span class="call-now-text">Call now!</span> <a href="tel:+18007535732">(800) 753-5732</a></li>
                <li><a class="btn btn-rounded btn-orange btn-sign-up " href="/start">Sign Up</a></li>
                <li><a class="btn btn-rounded btn-log-in" href="https://app.eztexting.com/">Log In</a></li>
            </ul>
        </div><!--/.nav-collapse -->
    </div>
</div>
