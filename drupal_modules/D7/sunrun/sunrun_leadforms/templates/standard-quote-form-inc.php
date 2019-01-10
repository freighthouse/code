<?php
if ($sidebar == false) {
  $label_class = "col-sm-2";
  $input_class = "col-sm-10";
  $checkbox_class = "col-sm-offset-2 col-sm-10";
  $form_class = "form-horizontal";
  $submit_class = "";
}
else {
  $label_class = "";
  $input_class = "";
  $checkbox_class = "";
  $form_class = "";
  $submit_class = "";
}

if ( isset($inline) ){
  $form_class .= " form-inline";
  $label_class = "no-show";
  $input_class = "col-sm-12";
  $checkbox_class = "col-md-6 col-md-push-3";
  $submit_class = "col-md-12";
}

$zip = isset($_GET['zip']) && is_numeric($_GET['zip']) ? $_GET['zip'] : "";

$current_url = $actual_link = "http://$_SERVER[HTTP_HOST]$_SERVER[REQUEST_URI]";
?>

<form action="//www.sunruntransit.com/track/lead" autocomplete="on" class="<?php echo $form_class; ?> zeus-quote-form" id="zeus-quote-form" method="post">
  <div class="form-group">
    <label class="<?php echo $label_class; ?>" for="zip">Zip Code</label>
    <div class="<?php echo $input_class; ?>">
      <input autocomplete="postal-code" class="form-control" id="zip" name="zip" placeholder="99999" value="<?php echo $zip; ?>" />
    </div>
  </div>
  <div class="form-group">
    <label class="<?php echo $label_class; ?>" for="first_name">First Name</label>
    <div class="<?php echo $input_class; ?>">
      <input autocomplete="given-name" class="form-control" type="text" id="first_name" name="first_name" placeholder="First Name"  value=""/>
    </div>
  </div>
  <div class="form-group">
    <label class="<?php echo $label_class; ?>" for="last_name">Last Name</label>
    <div class="<?php echo $input_class; ?>">
      <input autocomplete="family-name" class="form-control" type="text" id="last_name" name="last_name" placeholder="Last Name"  value="" />
    </div>
  </div>
  <div class="form-group">
    <label class="<?php echo $label_class; ?>" for="email">Email</label>
    <div class="<?php echo $input_class; ?>">
      <input autocomplete="email" class="form-control" type="email" id="email" name="email" placeholder="name@example.com"  value="" />
    </div>
  </div>
  <div class="form-group">
    <label class="<?php echo $label_class; ?>" for="phone">Phone</label>
    <div class="<?php echo $input_class; ?>">
      <input autocomplete="tel" class="form-control" type="tel" id="phone" name="phone" placeholder="(555) 555-5555"  value="" />
    </div>
  </div>
  <div class="form-group">
    <label class="<?php echo $label_class; ?>" for="electric_bill">Electric Bill</label>
    <div class="<?php echo $input_class; ?>">
      <select class="form-control" id="electric_bill" name="electric_bill" required>
        <option value="">-Select Average Monthly Bill-</option>
        <option value="$0-50">$0-50</option>
        <option value="$51-100">$51-100</option>
        <option value="$101-150">$101-150</option>
        <option value="$151-200">$151-200</option>
        <option value="$201-300">$201-300</option>
        <option value="$301-400">$301-400</option>
        <option value="$401-500">$401-500</option>
        <option value="$501-600">$501-600</option>
        <option value="$601-700">$601-700</option>
        <option value="$701-800">$701-800</option>
        <option value="$801+">$801+</option>
      </select>
    </div>
  </div>

    <div class="<?php echo $checkbox_class; ?>">
      <div class="checkbox">
        <label>
          <input name="additionalServices"  value="Energy Storage / Bright Box Battery" type="checkbox"<?php $path_alias = drupal_get_path_alias($_GET['q']); if (substr_count($path_alias, 'brightbox-solar-energy-battery')) { echo " checked='checked'"; }?>> I'm interested in Brightbox Solar Battery Storage
        </label>
      </div>
      <div class="checkbox">
        <label>
          <input name="Referral_web_form__c"  value="yes" type="checkbox"> I was referred to Sunrun by a friend or family member
        </label>
      </div>
    </div>
    <input id="campid" type="hidden" name="campid" value="">
    <input type="hidden" id="default_campid" name="default_campid" value="B08051BC1B15C238">
    <input type="hidden" name="ret_url" value="<?php echo $base_url; ?>/ty/thank-you">
    <input type="hidden" id="offerPromoCode" name="offerPromoCode" value=""  />
    <input type="hidden" name="Auto_dialer_Opt_in__c" value="1">
    <input type="hidden" name="technology" value="<?php echo $technology; ?>">
    <input type="hidden" name="Web_User_ID__c" value="">
    <input type="hidden" id="Application_client_id__c" name="Application_client_id__c" value="">
    <div class="text-center<?php echo " ".$submit_class; ?>">
      <button type="submit" class="btn btn-cta">Request a free quote</button>
    </div>
  <div class="row">
    <div class="col-sm-12 text-left">
    <small class="pageid-tcpa">
      <?php print $tcpa; ?>
    </small>
    </div>
  </div>
</form>
