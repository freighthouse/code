<?php
$can_use_iha = FALSE;
if (module_exists('iha_account')) {
  $server_name = strtolower($_SERVER['SERVER_NAME']);
  if (empty($server_name) && array_key_exists('HTTP_HOST', $_SERVER)) {
    $server_name = strtolower($_SERVER['HTTP_HOST']);
  }
  // Server host whitelist includes 'localhost' and *.iha.com.
  if ($server_name == 'localhost' || preg_match('!iha.com$!', $server_name)) {
    $can_use_iha = TRUE;
  }
}
?>
<div id="iha-sso-signin-block" class="clearfix">
  <ul class="federated-buttons">
    <?php if (module_exists('iha_sso')): ?>
    <li><?php echo l('Authenticate with Google', 'iha_sso', array('attributes' => array('class' => array('btn', 'google'))));?></li>
    <?php endif; ?>
    <?php if ($can_use_iha):?>
    <li><?php echo l("Authenticate with IHA", 'iha-login', array('attributes' => array('class' => array('btn', 'iha'))));?></li>
    <?php endif; ?>
    <?php if (module_exists("fbconnect")):?>
    <li><?php echo l('Authenticate with Facebook', 'facebook', array('attributes' => array('class' => array('btn', 'facebook'))));?></li>
    <?php endif; ?>
    <?php if (module_exists('twitter_signin')):?>
    <li><?php echo l('Authenticate with Twitter', 'twitter/redirect', array('attributes' => array('class' => array('btn', 'twitter'))));?></li>
    <?php endif; ?>
  </ul>
</div>
