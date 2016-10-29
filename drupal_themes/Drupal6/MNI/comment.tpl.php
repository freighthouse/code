<?php
    global $user;
if ($user->uid) :
    global $comment_count;
    $comment_count++;
    if ($comment_count == 1) {
        print '<div class="comments-area">'; 
    }
?>
<div class="comment">
    <?php if ($submitted) : ?>
    <span class="submitted"><?php print $submitted; ?></span>
    <?php endif; ?>
  <h4><?php print $title ?></h4>
 <div class="txt" style="float:left;">
    <?php
    if ($comment->picture) {
        print '<img class="icon" src="' . base_path() . $comment->picture . '" alt="image description" width="64" height="64"/>';
    } else if($picture) {
        print '<span class="icon">'.$picture.'</span>'; 
    }
    ?>
    </div>
		<div class="txt">
    <?php print $comment->comment; ?>
        <?php if ($signature) : ?>
      <div class="comment_sig_sep"></div>
        <?php print $signature ?>
        <?php endif; ?>
    </div>
	</div>
	<br clear="all" style="clear:both;"/>
<?php
if ($comment_count == $node->comment_count) {
    print '</div>'; 
}
endif;
