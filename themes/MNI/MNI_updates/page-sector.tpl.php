<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns:fb="http://www.facebook.com/2008/fbml" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
	<head>
<!--page-sector-->
		<?php print $head ?>
		<title><?php print $head_title ?></title>
		<?php print $styles; ?>
		<?php print $scripts; ?>
			
		<!--[if lt IE 8]>
			<?php print phptemplate_get_ie_styles(); ?>
		<![endif]-->
	</head>
	<body>
			<div id="wrapper">
				<img class="print-logo" src="<?php print template_path; ?>/images/logo.gif" alt="image description" />
				<div id="header">
					<?php print $top; ?>
                                        <!-- <form class="form-search" method="get" accept-charset="UTF-8" action="/article_search">
                                                <div>
                                                        <div class="container-inline" >
                                                                <div class="form-item">
                                                                        <input id="edit-search-theme-form-1" type="text" class="form-text" title="Enter the terms you wish to search for." value="search MNI" size="15" name="keys" id="keys" maxlength="128" onclick="if (this.value=='search MNI') {this.value=''};"/>
                                                                </div>
                                                                <input type="submit" class="form-submit" value="Search" />
                                                        </div>
                                                </div>
                                        </form> -->
					<h1 class="logo"><a href="<?php print check_plain($front_page); ?>"><?php print check_plain($site_name); ?></a></h1>
					<div class="navbar-holder">
						<div class="navbar">
							<em class="todays-date"><?php print strtoupper(date('l, F j, Y')); ?></em>
							<?php print $main_menu; ?>
						</div>
					</div>
					<div class="top-bar">

						<div class="box">		
							<?php 
								print $top_social_links; 
								//print $greeting_msg; 
								print mni_misc_functions_greeting_msg();
							?>
						</div>
						<?php print $scrolling_ticker; ?>
						<div id="drupal_msg"><?php if ($show_messages && $messages): print $messages; endif; ?></div>
					</div>
				</div>
				<div id="main">
					<div class="main-sep">
						<div id="content">
							<?php
								if ($tabbed_menu){
									print $tabbed_menu;
								}
							?>
							<?php if ($mission): print '<div id="mission">'. $mission .'</div>'; endif; ?>
							<?php if ($tabs): print '<div id="tabs-wrapper">'; endif; ?>
							<?php if ($tabs): print '<ul class="tabs primary">'. $tabs .'</ul></div>'; endif; ?>
							<?php if ($tabs2): print '<ul class="tabs secondary">'. $tabs2 .'</ul>'; endif; ?>
							<?php print $help; ?>
								
								
						<div class="single-post">
							<div class="post-content-type">
								<?php 
								/*
								this conditional prevents an empty view being displayed on the sector index pages.  
								those pages get their view from block-tabbed-menu.tpl.php
								*/
								if(arg(2)!="index") {
									print $content;
								}
								 ?>
							</div>
						</div>
							<?php 
								if ($bottom){
									print '<div class="index-block">' . $bottom . '</div>';
								}
							?>
						</div>
						<div id="sidebar">
							<?php print $right; ?>
							<div class="side-box"></div>
						</div>
					</div>
				</div>
				<div id="footer">
					<div class="major-wrap">
						<div class="frame">
							<?php print $footer; ?>
						</div>
						<div class="bottom-nav">
							<?php print $footer_nav; ?>
						</div>
					</div>
				</div>
			</div>

		<?php print $closure ?>
	</body>
</html>
