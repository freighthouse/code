<?php
//catch the plan
global $packageName;
global $country;

$country = (empty($_GET['country'])) ? 1 : $_GET['country'];
$packageName = (empty($_GET['pid'])) ? '' : $_GET['pid'];

if ($country == 1) {
  switch($packageName) {
    case 'paygo':
      $PackageID      = '1096';
      $PackageVerbose = 'Pay &amp; Go';
      break;
    case 'starter':
      $PackageID      = '415';
      $PackageVerbose = 'Starter';
      break;
    case 'plus':
      $PackageID      = '1097';
      $PackageVerbose = 'Plus';
      break;
    case 'select':
      $PackageID      = '1098';
      $PackageVerbose = 'Select';
      break;
    case 'elite':
      $PackageID      = '1099';
      $PackageVerbose = 'Elite';
      break;
    case 'pro':
      $PackageID      = '1100';
      $PackageVerbose = 'Pro';
      break;
    case 'bronze':
      $PackageID      = '1101';
      $PackageVerbose = 'Bronze';
      break;
    case 'silver':
      $PackageID      = '1102';
      $PackageVerbose = 'Silver';
      break;
    case 'gold':
      $PackageID      = '1103';
      $PackageVerbose = 'Gold';
      break;
    case 'free':
      $PackageID      = '1474';
      $PackageVerbose = 'Free &amp; Ez';
      break;
    default:
      $PackageID      = '1096';
      $PackageVerbose = 'Pay &amp; Go';
  }
} elseif ($country == 2) {
  switch($packageName) {
    case 'paygo':
      $PackageID      = '1104';
      $PackageVerbose = 'Pay &amp; Go';
      break;
    case 'plus':
      $PackageID      = '1105';
      $PackageVerbose = 'Plus';
      break;
    case 'select':
      $PackageID      = '1106';
      $PackageVerbose = 'Select';
      break;
    case 'elite':
      $PackageID      = '1107';
      $PackageVerbose = 'Elite';
      break;
    case 'pro':
      $PackageID      = '1108';
      $PackageVerbose = 'Pro';
      break;
    case 'bronze':
      $PackageID      = '1109';
      $PackageVerbose = 'Bronze';
      break;
    case 'silver':
      $PackageID      = '1110';
      $PackageVerbose = 'Silver';
      break;
    case 'gold':
      $PackageID      = '1111';
      $PackageVerbose = 'Gold';
      break;
    case 'free':
      $PackageID      = '1518';
      $PackageVerbose = 'Free &amp; Ez';
      break;
    default:
      $PackageID      = '1104';
      $PackageVerbose = 'Pay &amp; Go';
  }
}

if ($PackageID == 1518 || $PackageID == 1104 || $PackageID == 1096 || $PackageID == 1474) {
  $buttonText = 'Start for free';
} else {
  $buttonText = 'Create your account';
}


?>

<script>

jQuery(document).ready(function($) {
  var newPlanID, newPlanName;
  //convert canadian package and vice versa
  function convertPackageID(currentValue) {
    if ($('#AccountCountry').val() == 1) {
      switch(currentValue) {
        case '66':
          newPlanID       = '1096';
          newPlanName     = 'Pay & Go';
          break;
        case '54':
          newPlanID       = '1097';
          newPlanName     = 'Plus';
          break;
        case '55':
          newPlanID       = '1098';
          newPlanName     = 'Select';
          break;
        case '56':
          newPlanID       = '1099';
          newPlanName     = 'Elite';
          break;
        case '165':
          newPlanID       = '1100';
          newPlanName     = 'Pro';
          break;
        case '59':
          newPlanID       = '1101';
          newPlanName     = 'Bronze';
          break;
        case '61':
          newPlanID       = '1102';
          newPlanName     = 'Silver';
          break;
        case '63':
          newPlanID       = '1103';
          newPlanName     = 'Gold';
          break;
        case '1518':
          newPlanID       = '1474';
          newPlanName     = 'Free & Ez';
          break;
        default:
          newPlanID       = '1096';
          newPlanName     = 'Pay & Go';
      }
    } else if ($('#AccountCountry').val() == 2) {
      switch(currentValue) {
        case '6':
          newPlanID       = '1104';
          newPlanName     = 'Pay & Go';
          break;
        case '49':
          newPlanID       = '1105';
          newPlanName     = 'Plus';
          break;
        case '50':
          newPlanID       = '1106';
          newPlanName     = 'Select';
          break;
        case '51':
          newPlanID       = '1107';
          newPlanName     = 'Elite';
          break;
        case '164':
          newPlanID       = '1108';
          newPlanName     = 'Pro';
          break;
        case '58':
          newPlanID       = '1109';
          newPlanName     = 'Bronze';
          break;
        case '60':
          newPlanID       = '1110';
          newPlanName     = 'Silver';
          break;
        case '62':
          newPlanID       = '1111';
          newPlanName     = 'Gold';
          break;
        case '1474':
          newPlanID       = '1518';
          newPlanName     = 'Free & Ez';
          break;
        default:
          newPlanID       = '1104';
          newPlanName     = 'Pay & Go';
      }
    }
    $('input[name="PackageID"]').attr('value', newPlanID);
    $('.plan-name').text(newPlanName);
  }

  $('#AccountCountry').on('change', function() {
    convertPackageID($('input[name="PackageID"]').val());
  });

});
</script>

<div id="signup" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <!-- ______________________ HEADER _______________________ -->



  <div class="navbar navbar-default" role="navigation">
    <div class="container">
      <div class="navbar-header">
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="navbar-brand">
            <img src="<?php print base_path() . path_to_theme() . "/images/ez-texting-logo-white.png"; ?>" alt="<?php print t('Home'); ?>">
          </a>
        </div>
      <ul class="nav navbar-nav navbar-right">
        <li class="phone-number">Call now! <a href="tel:+18007535732">(800) 753-5732</a></li>
        <li><a class="btn btn-rounded btn-orange" href="https://app.eztexting.com">Log In</a></li>
      </ul>
    </div>
  </div>


  <?php if ($page['header']): ?>
      <?php print render($page['header']); ?>
  <?php endif; ?>



  <!-- ______________________ MAIN _______________________ -->

  <div class="hero-int">
    <div class="container">
      <?php if ($packageName) { ?>
        <h1 class="title">Let's Create Your <span class="plan-name"><?php echo $PackageVerbose ?></span> Account!</h1>
      <?php } elseif ($title) { ?>
        <h1><?php print $title; ?></h1>
      <?php } ?>
      <?php if (get_node_field($node, 'field_subtitle') && $PackageID != '1474') { ?>
        <h2>[ <?php print get_node_field($node, 'field_subtitle'); ?> ]</h2>
      <?php } ?>
    </div>
  </div>

  <?php if ($messages || $tabs || $action_links): ?>
  <div class="container">
    <div id="content-header" class="row">

      <?php if ($page['highlight']): ?>
        <div id="highlight"><?php print render($page['highlight']) ?></div>
      <?php endif; ?>

      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php print render($page['help']); ?>

      <?php if ($tabs): ?>
        <div class="tabs"><?php print render($tabs); ?></div>
      <?php endif; ?>

      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>

    </div> <!-- /#content-header -->
  </div>
  <?php endif; ?>

  <section class="content-wrap">
    <div class="container">
      <div class="row">
        <div class="col-md-6 content">

          <form enctype="application/x-www-form-urlencoded" action="https://app.eztexting.com/guest/signup" method="post" id="signup-form" role="form">
            <div class="form-group">
              <label for="userName" class="control-label">Username</label>
              <input name="userName" id="userName" class="form-control" type="text" maxlength="12" value="" required>
              <p class="help-block">Up to 12 characters</p>
            </div>

            <div class="form-group">
              <label for="email" class="control-label">Email</label>
              <input type="text" name="email" id="email" class="form-control" value="">
            </div>

            <div class="form-group">
              <label for="password" class="control-label">Password</label>
              <input name="password" id="password" class="form-control" type="password" value="" maxlength="50" required>
              <p class="help-block">5 characters or more.</p>
            </div>

            <div class="form-group">
              <label for="AccountCountry" class="control-label">Deliver My Texts To</label>
              <select id="AccountCountry" name="AccountCountry" class="form-control" required>
                <?php
                $selectedHTML = 'selected="selected"';
                if ($country == 2) {
                  $selectCanada = $selectedHTML;
                  $selectUS = '';
                } else {
                  $selectUS = $selectedHTML;
                  $selectCanada = '';
                }
                ?>
                <option value="1" <?php echo $selectUS; ?>>USA</option>
                <option value="2" <?php echo $selectCanada; ?>>Canada</option>
              </select>
            </div>

            <input type="hidden" name="newOnboarding" value="true">
            <input type="hidden" name="PackageID" value="<?php echo $PackageID ?>" />
            <input name="submit" type="submit" value="<?php echo $buttonText; ?>" class="btn btn-lg btn-rounded btn-orange">

            <p class="text-muted">
              By registering you agree to the <a href="/terms" target="_blank">terms and conditions</a> and <a href="/anti-spam-policy">anti-spam policy</a>.<br>
              Ez Texting has a zero tolerance policy for spamming or phishing.<br>
              All messages on our system are monitored and your IP address is logged.
            </p>
          </form>

        </div>
        <div class="col-md-6">
          <?php print render($page['content']) ?>
        </div>
      </div>
      <?php if ($page['content_bottom']) { ?>
          <div class="row">
            <?php print render($page['content_bottom']) ?>
          </div>
        <?php } ?>
    </div>
  </section>

  <!-- ______________________ FOOTER _______________________ -->

  <?php
    include "./".path_to_theme()."/includes/footer-landing.inc";
  ?>

</div> <!-- /page -->
<?php print render($page['footer']) ?>