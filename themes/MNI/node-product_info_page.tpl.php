<div class="post">
	<div class="main-heading">
		<!--<?php if (!$user->uid):?><strong class="note">Unlock up-to-the-minute financial news. <a href="/user/register">Sign up today.</a></strong><?php endif; ?>-->
		<?php print '<h2>' . $title.'</h2>'; ?>
	</div>
	<div class="bar">
		<ul>
			<li><a href="<?php print url('print/'.$node->nid); ?>">Print</a></li>
			<li><a href="<?php print url('printmail/'.$node->nid); ?>">Email</a></li>
		</ul> 
	</div>
<?php if(mni_misc_functions_is_user_subscribed($node->nid)){ ?>
	<h3><a href="/mni-dashboard">You are subscribed to this product.  Click here to access it.</a></h3>
<?php } ?>
	<div class="content">
		<?php print '<div class="img"><img src="/'.$node->field_top_image[0]['filepath'].'" alt=""></div>'; ?>
		<?php print($content); ?>
	</div>
	<?php if ($node->field_download_pdf[0]['filepath'] || $node->field_more_link[0]['value']) : ?>
		<ul class="meta-list">
			<?php
				if ($node->field_download_pdf[0]['filepath'])
					print '<li><a href="' . base_path() . $node->field_download_pdf[0]['filepath'] . '" target="_blank">DOWNLOAD PRODUCT SHEET [PDF]</a></li>';
				if ($node->field_more_link[0]['value'])
					print '<li><a href="' . $node->field_more_link[0]['value'] . '">GET MORE INFORMATION</a></li>';
			?>
		</ul>
	<?php endif; ?>
				<h3>SUBSCRIBE TODAY:</h3>
	<?php 
	if ($node->field_form_subscribe[0]['value'] != 'Yes'){
		//no form - just link.  the form, if printed is in a different content region, so is handled in page.tpl.php
	?>
		<a href='https://contracts.deutsche-boerse.com/mda-register?ext=l:0;ct:12597;n:1071'>Click here to sign up online</a><br/>
		<a href='/content/request-free-trial?product=<?php echo(check_url(arg(1))); ?>'>Click here to request a free trial</a>
	<?php 
	}
	?>

</div>
