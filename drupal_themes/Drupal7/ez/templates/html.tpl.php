<!DOCTYPE html>
<!--[if IE 8]><html class="lt-ie9 lt-ie10"><![endif]-->
<!--[if IE 9]><html class="lt-ie10"><![endif]-->
<!--[if (gte IE 10)|(gt IEMobile 7)]><!-->
<html lang="en">
<!--<![endif]-->
<head profile="<?php print $grddl_profile; ?>">
  <script type="text/javascript">
    dataLayer = [];
  </script>
  <?php
    $load_gtm = variable_get('load_gtm');
    if ($load_gtm == true) { ?>
  <!-- Google Tag Manager -->
  <script>(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({'gtm.start':
  new Date().getTime(),event:'gtm.js'});var f=d.getElementsByTagName(s)[0],
  j=d.createElement(s),dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src=
  'https://www.googletagmanager.com/gtm.js?id='+i+dl;f.parentNode.insertBefore(j,f);
  })(window,document,'script','dataLayer','GTM-KV2J2V');</script>
  <!-- End Google Tag Manager -->
  <?php } ?>

  <script type="text/javascript">
    var fontCookie = document.cookie.replace(/(?:(?:^|.*;\s*)_ez_fonts_loaded\s*\=\s*([^;]*).*$)|^.*$/, "$1");
    if (fontCookie) {
      document.documentElement.classList.add('fonts-loaded');
    }
  </script>

  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">

  <?php print $styles; ?>
  <?php print $scripts; ?>

  <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
  <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
  <!--[if lt IE 9]>
    <script src="//oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
    <script src="//oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
  <![endif]-->
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php if ($load_gtm == true) { ?>
  <!-- Google Tag Manager (noscript) -->
  <noscript><iframe src="https://www.googletagmanager.com/ns.html?id=GTM-KV2J2V"
  height="0" width="0" style="display:none;visibility:hidden"></iframe></noscript>
  <!-- End Google Tag Manager (noscript) -->
  <?php } ?>

  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>

  <?php
    include "./".path_to_theme()."/includes/fontsjs.inc";
  ?>

</body>
</html>
