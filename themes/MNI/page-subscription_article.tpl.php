<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns:fb="http://www.facebook.com/2008/fbml" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
	<head>
<!--page-subscription_article-->
<?php
/* this template displays a single subscription article in the pop up window style */
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
                <a class="printicon" href="<?php print url('print/'.$node->nid); ?>">Print</a>
                <a class="close win-close" href="#">Close</a>
                <a class="logo2" href="<?php print check_plain($front_page); ?>"><?php print check_plain($site_name); ?></a>
				<h3>MNI Wire</h3>
			</div>
			<div class="holder">
				<div class="news">
					<?php if ($mission): print '<div id="mission">'. $mission .'</div>'; endif; ?>
					<?php if ($tabs): print '<div id="tabs-wrapper">'; endif; ?>
					<?php if ($tabs): print '<ul class="tabs primary">'. $tabs .'</ul></div>'; endif; ?>
					<?php if ($tabs2): print '<ul class="tabs secondary">'. $tabs2 .'</ul>'; endif; ?>
					<div id="drupal_msg"><?php if ($show_messages && $messages): print $messages; endif; ?></div>
      <?php print $help; ?>
					<h4><?php print $title; ?></h4>
					<em class="date"><?php print date ('h:i T / M d', $node->created); ?></em>
                    
					<div class="txt">
		<?php 
			if(mni_misc_functions_node_is_txttbl($node)){
				print("<pre>".str_replace("<br />","",$node->body)."</pre>");
			} else {
				print($node->body);
			}
		?> 
		
<?php 
	if ($node->taxonomy){ 
?>
	<div class="meta">
	<h2 class="nodesection">See Related Headlines:</h2>
<?php 
		$links=MNI_taxonomy_link($node);
		print theme('links', $links);
?>
	</div>
<?php 
	}
?>
		<h2>Comments 
		<?php
			if ($node->comment_count){
				print '<span class="comments">(' . $node->comment_count . ')</span>';
			} ?></h2><?php
			
			print $comments; 
			print $below_content; 

		?>


					</div>
				</div>                    
			</div>
		</div>

		<?php print $closure ?>
	</body>
</html>