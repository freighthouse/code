<?php
/**
 * @file alacarte_body.tpl.php
 *
 * Variables available:
 *
 *      $nid
 *      $title
 *			$taxonomy
 *      $body
 *			$postdate
 *			$comment_count
 *			$hdr
 *			$loggedin (bool)
 *			$acl_access (bool)
 *			$product_nid - id of the articles corresponding ubercart product
 */
?>
<div class="post-content-type">
	<div class="main-heading">
<?php if (!$loggedin):?>
		<strong class="note">Unlock up-to-the-minute financial news. <a href="/user/register">Sign up today.</a></strong>
<?php endif; ?>
	<?php
			//print '';
			print '<h2>'.$hdr;
			if (!$acl_access){
				print ' <img src="' . template_path .'/images/icon-key.gif" alt="image description" />';
			}
			print '</h2>';
		?>
	</div>
<?php if (!$acl_access):?>
	<div class="content">
		<em class="date"><?php print $postdate; ?></em>
		<h3><?php print $title ?></h3>
		<?php
		if(mni_misc_functions_node_is_txttbl(NULL,$taxonomy)){
			print("<pre>".str_replace("<br />","",$body)."</pre>");
		} else {
			print($body);
		}
		?>
	</div>
	<div class="bar">
	<?php if (!$loggedin):?>
		<a href="/user" >LOGIN</a> TO PURCHASE ARTICLE
	<?php else : ?>
		<a href="/cart/add/p<?php echo($product_nid);?>?destination=cart/checkout" >CLICK</a> TO PURCHASE ARTICLE
	<?php endif; ?>
	</div>
</div>
<?php else : ?>
	<div class="bar">
		<?php $fb_url = url('node/'. $node->nid ,array('absolute' => TRUE));?>
		<div id = "mnifacebook"><iframe src="https://www.facebook.com/plugins/like.php?app_id=218603084819579&amp;href=<?php print $fb_url; ?>&amp;send=false&amp;layout=button_count&amp;width=450&amp;show_faces=false&amp;action=like&amp;colorscheme=light&amp;font&amp;height=21" scrolling="no" frameborder="0"  allowTransparency="true"></iframe></div>

		<div id = "mnitwitter"><a href="https://twitter.com/share" class="twitter-share-button" data-count="none"></a></div>

		<div id = "mnigoogle"><div class="g-plusone" data-size="medium" data-annotation="none"></div></div>

		<div id = "mnilinkedin"><script src="https://platform.linkedin.com/in.js" type="text/javascript"> </script><script type="IN/Share" data-counter="none"></script></div>

		<?php
			if ($comment_count)
				print '<span class="comments">' . $comment_count . '</span>';
		?>
		<ul>
			<li><a href="<?php print url('print/'.$nid); ?>">Print</a></li>
			<li><a href="<?php print url('printmail/'.$nid); ?>">Email</a></li>
		</ul>
	</div>
	<em class="date"><?php print $postdate; ?></em>
	<h3><?php print $title; ?></h3>
	<?php
	if(mni_misc_functions_node_is_txttbl(NULL,$taxonomy)){
		print("<pre>".str_replace("<br />","",$body)."</pre>");
	} else {
		print($body);
	}
	?>
</div>

<?php endif;
