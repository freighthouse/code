<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns:fb="http://www.facebook.com/2008/fbml" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
	<head>
<!--page-subscription_articles-->
<?php
/* this template displays a taxonomy term based list of subscription articles in the pop up window style */
print $head;
?>
		<title><?php print $head_title ?></title>
    <?php print $styles ?>
    <?php print $scripts; ?>
		<!--[if lt IE 8]>
    <?php print phptemplate_get_ie_styles(); ?>
		<![endif]-->
	</head>
	<body>
		<div class="lightbox2">
			<div class="heading">
				<a class="close win-close" href="#">Close</a>
				<a class="logo2" href="<?php print check_plain($front_page); ?>"><?php print check_plain($site_name); ?></a>
				<h3><?php print $title ?></h3>
			</div>
			<div class="holder">
				<?php if ($mission) : print '<div id="mission">'. $mission .'</div>'; 
    endif; ?>
				<?php if ($tabs) : print '<div id="tabs-wrapper">'; 
    endif; ?>
				<?php if ($tabs) : print '<ul class="tabs primary">'. $tabs .'</ul></div>'; 
    endif; ?>
				<?php if ($tabs2) : print '<ul class="tabs secondary">'. $tabs2 .'</ul>'; 
    endif; ?>
				<div id="drupal_msg"><?php if ($show_messages && $messages) : print $messages; 
   endif; ?></div>
				<?php print $help; ?>
				<?php print $content; ?>
			</div>
		</div>
    <?php mni_dashboard_tracker(check_plain(arg(1)), check_plain(arg(2))); ?>
    <?php print $closure ?>
	</body>
</html>
