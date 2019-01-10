<!DOCTYPE html>
<!--[if IEMobile 7]><html class="iem7"><![endif]-->
<!--[if lte IE 6]><html class="lt-ie9 lt-ie8 lt-ie7 lt-ie10"><![endif]-->
<!--[if (IE 7)&(!IEMobile)]><html class="lt-ie9 lt-ie8 lt-ie10"><![endif]-->
<!--[if IE 8]><html class="lt-ie9 lt-ie10"><![endif]-->
<!--[if IE 9]><html class="lt-ie10"><![endif]-->
<!--[if (gte IE 10)|(gt IEMobile 7)]><!--><html><!--<![endif]-->
<head profile="<?php print $grddl_profile; ?>">
	<?php print $head; ?>
  <title><?php print $head_title; ?></title>

  <?php print $styles; ?>

	<!--[if lt IE 9]>
	<script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
	<![endif]-->

</head>
<body class="<?php print $classes; ?>">
	<?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $scripts; ?>
  <?php print $page_bottom; ?>
</body>
</html>