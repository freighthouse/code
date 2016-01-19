<?php
unset($form['submitted']['message']['#title']);
unset($form['submitted']['message']['#suffix']);
unset($form['actions']['submit']);
?>
<div class="main-heading">
<h2>Ask the Managing Editor</h2>
</div>
<?php print "You are coming from ".$_SERVER["REMOTE_ADDR"] ?>
<div class="person">
<img class="icon" src="<?php print template_path; ?>/images/tonymace.jpg" alt="Tony Mace" />
<div class="title">Tony Mace takes on your questions.</div>
</div>
<div class="row">
<?php print drupal_render($form['submitted']['message']) ?>
</div>
<div class="row">
<input class="submit" type="submit" value="submit" />
</div>
<?php print drupal_render($form) ?>