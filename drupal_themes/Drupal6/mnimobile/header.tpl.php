<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
<head>
	<meta name="MobileOptimized" content="width" />
	<meta name="viewport" content="width=device-width, maximum-scale=1.0, initial-scale=1.0 , user-scalable=0;" />
    <?php print $head; ?>
	<title><?php
    if (drupal_is_front_page()) {
        print "MNI News | MNI";
    }else{
        print $head_title ;
    }
    ?></title>
    <?php print $styles ?>
    <?php print $scripts ?>
	<script type="text/javascript" src="<?php print base_path() . path_to_theme(); ?>/js/clear-input.js"></script>
</head>
<body>
	<div id="wrapper">
		<div class="w1">
    <?php if ($top_menu) : ?>
				<div class="top-navigation">
        <?php print $top_menu; ?>
				</div>
    <?php endif; ?>
			<div id="header">
				<h1 class="logo"><a href="<?php print $front_page ?>"><?php print $site_name; ?></a></h1>
				<div class="holder">
        <?php print str_replace('value=""', 'value="search MNI"', $search_box); ?>
					<div class="wrap">
						<ul class="social-networks">
							<li><a href="https://www.facebook.com/MNINews" class="facebook">facebook</a></li>
							<li><a href="https://twitter.com/#!/MNINews" class="twitter">twitter</a></li>
							<li><a href="https://www.linkedin.com/groups/MNI-Financial-News-Group-3972504" class="linkedin">LinkedIn</a></li>
							<li><a href="https://www.youtube.com/MNINews" class="youtube">youtube</a></li>
						</ul>
					</div>
				</div>
			</div>
			<div id="main">
				<?php
    if ($main_menu) : ?>
					<div class="nav-box">
						<div class="holder">
        <?php print $main_menu; ?>
						</div>
					</div>
    <?php endif; ?>
