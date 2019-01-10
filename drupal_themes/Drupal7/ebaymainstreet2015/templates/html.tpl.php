<!DOCTYPE html>
<html class="no-js" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>
<head>
  <title><?php print $head_title; ?></title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <?php print $head; ?>

  <link href="<?php print base_path() . drupal_get_path('theme', 'ebaymainstreet2015'); ?>/images/apple-touch-icon-76x76.png" rel="apple-touch-icon" sizes="76x76" />
  <link href="<?php print base_path() . drupal_get_path('theme', 'ebaymainstreet2015'); ?>/images/apple-touch-icon-120x120.png" rel="apple-touch-icon" sizes="120x120" />
  <link href="<?php print base_path() . drupal_get_path('theme', 'ebaymainstreet2015'); ?>/images/apple-touch-icon-152x152.png" rel="apple-touch-icon" sizes="152x152" />
  <link href="<?php print base_path() . drupal_get_path('theme', 'ebaymainstreet2015'); ?>/images/apple-touch-icon-180x180.png" rel="apple-touch-icon" sizes="180x180" />
  <link href="<?php print base_path() . drupal_get_path('theme', 'ebaymainstreet2015'); ?>/images/apple-touch-icon-1024x1024.png" rel="apple-touch-icon" sizes="1024x1024" />


  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>">
  <?php print $page_top; ?>
  <a href="#main" class="skip-link" id="skip-to-main"><?php print t('Skip to main content'); ?></a>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>
