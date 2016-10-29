<?php
unset($form['Personal information']['profile_first_name']['#title']);
unset($form['Personal information']['profile_first_name']['#description']);
unset($form['Personal information']['profile_last_name']['#title']);
unset($form['Personal information']['profile_first_name']['#description']);
unset($form['Personal information']['profile_company']['#title']);
unset($form['Personal information']['profile_first_name']['#description']);
unset($form['account']['name']['#title']);
unset($form['account']['name']['#description']);
unset($form['account']['mail']['#title']);
unset($form['account']['mail']['#description']);
unset($form['account']['conf_mail']['#title']);
unset($form['account']['conf_mail']['#description']);
unset($form['account']['pass']['pass1']['#title']);
unset($form['account']['pass']['pass1']['#description']);
unset($form['account']['pass']['pass2']['#title']);
unset($form['account']['pass']['pass2']['#description']);
?>
<div class="row">
	<div class="box">
		<label for="f-fname">First Name</label>
		<div class="text"><?php print drupal_render($form['Personal information']['profile_first_name']); ?></div>
	</div>
	<div class="box">
		<label for="f-lname">Last Name</label>
		<div class="text"><?php print drupal_render($form['Personal information']['profile_last_name']); ?></div>
	</div>
</div>
<div class="row">
	<div class="box">
		<label for="f-company">Company</label>
		<div class="text"><?php print drupal_render($form['Personal information']['profile_company']); ?></div>
	</div>
</div>
<div class="row">
	<div class="box">
		<label for="f-create">Create a User Name</label>
		<div class="text"><?php print drupal_render($form['account']['name']); ?></div>
	</div>
</div>
<div class="row">
	<div class="box">
		<label for="f-email">Email Address</label>
		<div class="text"><?php print drupal_render($form['account']['mail']); ?></div>
	</div>
<!--	<div class="box">
		<label for="f-email2">Reenter Email Address</label>
		<div class="text"><?php print drupal_render($form['account']['conf_mail']); ?></div>
	</div>-->
</div>
<div class="row">
	<div class="box">
		<label for="f-password">Password</label>
		<div class="text"><?php print drupal_render($form['account']['pass']['pass1']); ?></div>
	</div>
	<div class="box">
		<label for="f-password2">Reenter Password</label>
		<div class="text"><?php print drupal_render($form['account']['pass']['pass2']); ?></div>
	</div>
</div>
<div class="row">
	<input class="submit" type="submit" value="Continue" />
</div>
<?php
      print drupal_render($form['timezone']);
      print drupal_render($form['form_build_id']);
      print drupal_render($form['form_id']);
      print drupal_render($form['form_token']);
