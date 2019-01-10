<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page while offline.
 *
 * All the available variables are mirrored in html.tpl.php and page.tpl.php.
 * Some may be blank but they are provided for consistency.
 *
 * @see template_preprocess()
 * @see template_preprocess_maintenance_page()
 *
 * @ingroup themeable
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">

<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>">
<div id="page">
  <header id="header" class="clearfix" role="banner">
    <div class="clearfix">
      <div id="logo-title">

          <?php if (!empty($logo)): ?>
            <a href="<?php print $base_path; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
              <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
            </a>
          <?php endif; ?>
      </div>
      <div id="block-system-main-menu">
        <ul class="menu">
          <li class="leaf menu-214261"><a href="https://www.callfire.com/ui/login" title="CallFire Admin Login">Login</a></li>
          <li class="last leaf menu-391001"><a href="https://www.callfire.com/dialer/agents/userlogin.do" title="Agents Login">Agents</a></li>
        </ul>
      </div>
    </div>
  </header>

  <div id="maintenance" class="clearfix">
    <div id="content" class="clearfix">
        <div class="grid-5 prepend-1" role="main">
          <?php if (!empty($title)): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
          <?php if (!empty($messages)): print $messages; endif; ?>
          <div id="content-content" class="clearfix">
            <?php print $content; ?>
          </div> <!-- /content-content -->
        </div> 
        <div class="footer grid-6">
          <p>
            Contact us at (877) 897-FIRE or by e-mail <a href="mailto:support@callfire.com">support@callfire.com</a>
          </p>
        </div>
    </div><!-- /#content -->

    <?php print render($page['content_bottom']); ?>
    
  </div><!-- /#maintenance -->

  <?php print render($page['footer_links']); ?>
  <?php print render($page['footer']); ?>

</div><!-- /#page -->

</body>
</html>
