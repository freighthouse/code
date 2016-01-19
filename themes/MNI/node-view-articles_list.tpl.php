<em class="date"><?php print date('l, F j, Y - H:i', $node->created); ?></em>
<?php
	if ($node->comment_count)
		print '<span class="comment">' . $node->comment_count . '</span>';
?>
<a class="title" href="<?php print $node_url ?>"><?php print $title ?></a>
<?php print $node->content['body']['#value']; ?>
