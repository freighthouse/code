


    <div class="navbar-v7">
      <div class="logo-container">
        <img class="logo vert-center" src="<?php print base_path() . path_to_theme() . "/images/ez-texting-logo-white.png"; ?>" alt="<?php print t('Home'); ?>">
        <!-- <img class="logo vert-center" src="/sites/default/files/purple/logo_landing4.png"> -->
      </div>
      <div class="mobile-nav">
        <button class="hamburger">&#9776;</button>
        <button class="cross">&#735;</button>
      </div>
      <div class="menu">
        <ul>
          <a href="https://app.eztexting.com/"><li>Login</li></a>
          <a href="https://www.eztexting.com/start"><li>Sign Up</li></a>
          <a href="https://www.eztexting.com/pricing"><li>Pricing</li></a>
        </ul>
      </div>
      <ul class="left-nav hide-li">
        <a href="https://www.eztexting.com/how-sms-marketing-works"><li>Features</li></a>
        <a href="https://www.eztexting.com/pricing"><li>Pricing</li></a>
        <a href="https://www.eztexting.com/who"><li>Who</li></a>
        <a href="https://www.eztexting.com/why-ez-texting"><li>Why</li></a>
        <a href="https://www.eztexting.com/blog"><li>Blog</li></a>
      </ul>
      <ul class="right-nav hide-li">
        <li><span id="call">Call now!</span>  <span id="number"><?php print get_node_field($node, 'field_phone_numb') ?></span></li>
        <li class="log-border-v7 hide-li"><a href="https://app.eztexting.com/" class="login">Log In</a></li>
        <li class="sign-border-v7 hide-li"><a href="https://www.eztexting.com/start" class="sign-up-v7">Sign Up</a></li>
      </ul>
    </div>

<script type="text/javascript">
(function ($) {
  // Use jQuery with the shortcut:
  // console.log($.browser);
// Here we immediately call the function with jQuery as the parameter.

$( ".cross" ).hide();
$( ".menu" ).hide();
$( ".hamburger" ).click(function() {
  $( ".menu" ).slideToggle( "slow", function() {
    $( ".hamburger" ).hide();
    $( ".cross" ).show();
  });
});

$( ".cross" ).click(function() {
  $( ".menu" ).slideToggle( "slow", function() {
    $( ".cross" ).hide();
    $( ".hamburger" ).show();
  });
});


}(jQuery));

</script>
