<!-- // standard-leadform-mulit-step-hor.tpl.php -->
<div class="container-fluid">
  <ul id="progressbar" class="progressbar">
    <li class="active"><span>1</span></li>
    <li><span>2</span></li>
    <li><span>3</span></li>
  </ul>
  <div class="row">
    <div class="col-sm-7 col-md-5">
      <!-- <h2 class="pane-title">Solar savings are big!</h2> -->
       <h3 class="pane-subtitle">See if you qualify</h3>
       <h4 class="pane-tabtitle">Go solar in 3 easy steps</h4>
    </div>
    <div class="col-sm-5 col-md-7">
      <div class="form-container">
        <div class="row">
          <div class="col-sm-12 col-md-offset-3 col-md-9 col-lg-offset-1 col-lg-11">
            <form id="multi-step-form" method="post" autocomplete="on" action="#" novalidate="novalidate">
            <!-- fieldsets -->
              <fieldset id="first">
                <legend class="field-title">Do you own your home?</legend>
                <div class="radio">
                    <input type="radio" name="property_ownership" id="property_ownership-OWN" value="OWN" checked>
                     <label for="property_ownership-OWN">Yes</label>
                </div>
                <div class="radio">
                    <input type="radio" name="property_ownership" id="property_ownership-RENT" value="RENT">
                    <label for="property_ownership-RENT"> No, I rent my home</label>
                </div>
                <div class="form-group">
                  <label for="zip"><input value="" placeholder="Zip Code" name="zip" maxlength="5" id="zip" class="form-control" autocomplete="postal-code" ></label>
                </div>
                <div class="btn-block">
                  <button class="btn next action-button" type="button" name="next">Next ></button>
                </div>
              </fieldset>
              <fieldset id="second">
                <legend class="field-title">What is your average monthly electric bill?</legend>
                <div class="form-group">
                  <div class="">
                    <select required name="electric_bill" id="electric_bill" class="form-control" aria-required="true">
                      <option value="" selected="">-Select Monthly Bill Amount</option>
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
                <div class="btn-block">
                  <button class="btn  next action-button" type="button" name="next">Next ></button>
                </div>
              </fieldset>
              <fieldset id="third">
                <div class="row">
                  <div class="form-group col-xs-6">
                      <input type="text" placeholder="First Name" name="first_name" class="form-control" autocomplete="given-name">
                  </div>
                  <div class="form-group col-xs-6">
                      <input type="text" placeholder="Last Name" name="last_name" class="form-control" autocomplete="family-name">
                  </div>
                </div>
                <div class="row">
                  <div class="form-group col-xs-6">
                      <input type="tel" placeholder="(555) 555-5555" name="phone" class="form-control" autocomplete="tel">
                  </div>
                  <div class="form-group col-xs-6">
                      <input type="email" placeholder="name@example.com" name="email" class="form-control" autocomplete="email">
                  </div>
                </div>
                <div class="row">
                  <div class="checkbox col-xs-12">
                    <label>
                      <input name="additionalServices"  value="Energy Storage / Bright Box Battery" type="checkbox"> I'm interested in Brightbox Solar Battery Storage
                    </label>
                    <label>
                      <input name="Referral_web_form__c"  value="yes" type="checkbox"> I was referred to Sunrun by a friend or family member
                    </label>
                  </div>
                </div>
                <div>
                  <input id="campid" type="hidden" name="campid" value="">
                  <input type="hidden" id="default_campid" name="default_campid" value="B08051BC1B15C238">
                    <input type="hidden" name="Auto_dialer_Opt_in__c" value="1">
                    <input type="hidden" name="technology" value="multistep">
                  <input type="hidden" name="Web_User_ID__c" value="">
                  <input type="hidden" id="Application_client_id__c" name="Application_client_id__c" value="">
                </div>
                <div class="row">
                  <div class="btn-block col-xs-12">
                    <button class="btn  submit action-button" type="submit" name="submit">Submit</button>
                  </div>
                </div>
                <div class="row">
                  <small class="pageid-tcpa col-sm-12 col-sm-6 col-lg-6">
                    <?php print $tcpa; ?>
                  </small>
                </div>
              </fieldset> <!-- // #third -->
            </form>

        </div> <!-- col-xs-10 -->
        <div class="thank-you">
          <h3 class="field-title">Thanks so much!</h3>
          <div class="btn-block">
            <a href="/referral" class="btn" target="_blank" style="">Refer a friend and get $350</a>
          </div>
          <p class="in-service-msg">We'll call you shortly.</p>
            <p class="out-of-service-msg"><?php print $oot_msg; ?></p>
        </div>

        </div> <!-- // row -->
      </div> <!-- form-container -->
    </div> <!-- col-xs-8 -->
  </div><!-- // row -->
</div> <!-- // container-fluid -->
