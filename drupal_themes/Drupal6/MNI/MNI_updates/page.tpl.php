<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns:fb="http://www.facebook.com/2008/fbml" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
<!--page-->
	<head>
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
					<!-- <form class="form-search" method="get" accept-charset="UTF-8" action="/search">
						<div>
							<div class="container-inline" >
								<div class="form-item">
									<input id="edit-search-theme-form-1" type="text" class="form-text" title="Enter the terms you wish to search for." value="search MNI" size="15" name="keys" id="keys" maxlength="128" onclick="if (this.value=='search MNI') {this.value=''};"/>
								</div>
								<input type="submit" class="form-submit" value="Search" />
							</div>
						</div>
					</form>					-->
					
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
						<div id="drupal_msg"><?php if ($show_messages && $messages) : print $messages; 
     endif; ?></div>
					</div>
				</div>
				<div id="main">
					<div class="main-sep">
						<div id="content">
        <?php
        if ($tabbed_menu) {
            print $tabbed_menu;
        }
        ?>
        <?php 
        if ($mission) : print '<div id="mission">'. $mission .'</div>'; 
        endif; 
        if ($tabs) : print '<div id="tabs-wrapper"><ul class="tabs primary">'. $tabs .'</ul></div>'; 
        endif; 
        if ($tabs2) : print '<ul class="tabs secondary">'. $tabs2 .'</ul>'; 
        endif; 
                                print $help; 
                                ?>
								
        <?php if ($node->type != 'product_info_page' && $node->type != 'alacarte_article' && !drupal_is_front_page()) : ?>
								
						<div class="single-post">
							<div class="post-content-type">
								<div class="main-heading">
        <?php if (!$user->uid) :?>
									<strong class="note">Unlock up-to-the-minute financial news. <a href="/user/register">Sign up today.</a></strong>
        <?php endif; ?>
        <?php
        if(!$node || $node->type == 'page') {
            $page_title=$title;
            if (!$page_title && arg(0) == 'taxonomy') {
                $tax_term = taxonomy_get_term(check_plain(arg(2)));
                if ($tax_term) {
                    $page_title=$tax_term->name;
                }
            }
            print '<h2>' . $page_title.'</h2>';
        } else {
            print '<h2>'.MNI_taxonomy_subhed($node).'</h2>';
        }
        ?>
								</div>

								<?php if($node && ($node->type == 'alacarte_article'||$node->type == 'free_article'||$node->type == 'page'||$node->type == 'product_info_page')) : ?>
								<div class="bar">
            <?php 
            if($node->type == 'alacarte_article'||$node->type == 'free_article') {
                $fb_url = "https%3A%2F%2Fmninews.deutsche-boerse.com".urlencode('/node/'. $node->nid);
            ?>
             <iframe src="https://www.facebook.com/plugins/like.php?app_id=218603084819579&amp;href=<?php print $fb_url; ?>&amp;send=false&amp;layout=button_count&amp;width=450&amp;show_faces=false&amp;action=like&amp;colorscheme=light&amp;font&amp;height=21" scrolling="no" frameborder="0" style="max-width: 97px; margin: -1px 1px -1px 0; border:none; overflow:hidden; width:auto; height:21px; float:right;" allowTransparency="true"></iframe>
            <?php
            }
            if ($node->comment_count) {
                print '<span class="comments">' . $node->comment_count . '</span>';
            }
            ?>
									<ul>
										<li><a href="<?php print url('print/'.$node->nid); ?>">Print</a></li>
										<li><a href="<?php print url('printmail/'.$node->nid); ?>">Email</a></li>
									</ul>
								</div>
								<?php endif; ?>
								<?php if($node->created && $node->type != 'page') : ?><em class="date"><?php print date('l, F j, Y - H:i', $node->created); ?></em><?php 
        endif; ?>
								<?php if($node && $node->type != 'page') : ?><h3><?php print $title; ?></h3><?php 
        endif; ?>
								<?php if($node && $node->type == 'chat') : ?><p><strong><a href="#online_users">Invite someone from the list of online users below</a></strong></p><?php 
        endif; ?>
								<?php print $above_content; ?>
								<?php print $content; ?>
								<?php print ($below_content); ?>

							</div>
						</div>
						
							
							
        <?php 
                                else : 
                                    print '<div class="single-post">'.$content.'</div>';
                                    print ($below_content);
                                endif; 
                                if ($bottom && $node->type != 'product_info_page' && $node->type != 'alacarte_article') {
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
