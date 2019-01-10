<div class="standard-leadform-horizontal-wide standard-leadform">
    <div class="inner">
    	<div class="row">
        <h2 class="blue" id="standard-leadform-horizontal-wide-headline">Contact Sunrun</h2>
    	</div><!-- //.row -->
      <div class="row">
          <div class="col-sm-12">
              <?php
              $inline = true;
              $label_class = "col-sm-2";
              $input_class = "col-sm-10";
              $checkbox_class = "col-sm-offset-2 col-sm-10";
              $form_class = "form-horizontal";
              $submit_class = "";

              $form_class .= " form-inline";
              $label_class = "no-show";
              $input_class = "col-sm-12";
              $checkbox_class = "col-md-6 col-md-push-3";
              $submit_class = "col-md-12";

            ?>

            <form action="//www.sunruntransit.com/track/lead" autocomplete="on" class="<?php echo $form_class; ?> zeus-quote-form" id="zeus-quote-form" method="post">
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

              <div class="<?php echo $checkbox_class; ?>">
                <div class="checkbox">
                  <label>
                    <input name="additionalServices"  value="Energy Storage / Bright Box Battery" type="checkbox"> I am interested in Brightbox Solar Battery Storage
                  </label>
                </div>
              </div>
              <input id="campid" type="hidden" name="campid" value="">
              <input type="hidden" id="default_campid" name="default_campid" value="B08051BC1B15C238">
              <input type="hidden" name="ret_url" value="https://www.sunrun.com/ty/thank-you">
              <input type="hidden" id="Channel_Last__c" name="Channel_Last__c" value="">
              <input type="hidden" id="Lead_Source_Last__c" name="Lead_Source_Last__c" value="">
              <input type="hidden" id="Campaign_Last__c" name="Campaign_Last__c" value="">
              <input type="hidden" id="Content_Last__c" name="Content_Last__c" value="quote form">
              <input type="hidden" id="Keywords_Last__c" name="Keywords_Last__c" value="">
              <input type="hidden" id="offerPromoCode" name="offerPromoCode" value=""  />
              <input type="hidden" name="Auto_dialer_Opt_in__c" value="1">
              <input type="hidden" id="Lead_Type_Last__c" name="Lead_Type_Last__c" value="">
              <input type="hidden" name="Web_User_ID__c" value="">
              <input type="hidden" id="Application_client_id__c" name="Application_client_id__c" value="">
              <div class="text-center submit<?php echo " ".$submit_class; ?>">
                <button type="submit" class="btn btn-cta">Submit</button>
              </div>
              <div class="row">
                <div class="col-sm-12 text-left">
                  <small class="pageid-tcpa">
                    <?php print $tcpa; ?>
                  </small>
                </div>
              </div>
            </form>
          </div><!-- /.col-sm-6 -->
      </div><!-- /.row -->
    </div><!-- /.inner -->
</div><!-- /.standard-leadform-horizontal -->
