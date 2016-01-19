<div class="main-heading">
	<!--<?php if (!$user->uid):?><strong class="note">Unlock up-to-the-minute financial news. <a href="/user/register">Sign up today.</a></strong><?php endif; ?>-->
	<h2><?php
	if (arg(0)=="sector"){
		echo(ucwords(str_replace("-"," ",check_url(arg(1)))));
		if (arg(2) && arg(2)!="index"){
			echo(": <br/>".ucwords(str_replace("-"," ",check_plain(arg(2)))));
		}
	}else{
		echo("Financial Market News");
	}
	?></h2>
</div>
<?php print $block->content; ?>