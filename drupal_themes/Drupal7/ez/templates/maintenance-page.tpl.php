<!DOCTYPE html>
<!--[if IEMobile 7]><html class="iem7"><![endif]-->
<!--[if lte IE 6]><html class="lt-ie9 lt-ie8 lt-ie7 lt-ie10"><![endif]-->
<!--[if (IE 7)&(!IEMobile)]><html class="lt-ie9 lt-ie8 lt-ie10"><![endif]-->
<!--[if IE 8]><html class="lt-ie9 lt-ie10"><![endif]-->
<!--[if IE 9]><html class="lt-ie10"><![endif]-->
<!--[if (gte IE 10)|(gt IEMobile 7)]><!--><html><!--<![endif]-->
<head>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=0">

  <?php /* Bootstrap CDN */ ?>
  <link href="//netdna.bootstrapcdn.com/bootstrap/3.1.1/css/bootstrap.min.css" rel="stylesheet">
  <link href="//netdna.bootstrapcdn.com/font-awesome/4.1.0/css/font-awesome.min.css" rel="stylesheet">
  <link href="//fonts.googleapis.com/css?family=Lato:300,400,700,300italic,400italic,700italic" rel="stylesheet" type="text/css">

  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
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
          <li><a class="btn btn-rounded btn-orange" href="https://app.eztexting.com">Log In</a></li>
        </ul>
      </div>
    </div>

    <section class="content-wrap slide" id="main">

    <!-- ______________________ MAIN _______________________ -->

      <div class="container" id="content">
        <div class="text-body">
          <?php print $content; ?>
        </div>
        <div class="sender">
          <p>Ez Texting</p>
          <div class="pull-right time">
            Today <?php echo date("g:i a"); ?>
          </div>
        </div>
      </div>

      <!-- ______________________ FOOTER _______________________ -->

    </section>

  </div> <!-- /page -->
</body>
</html>