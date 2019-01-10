<?php ?>
<form action="//www.sunruntransit.com/track/lead" autocomplete="on" class="zeus-quote-form standard-leadform" id="zeus-quote-form" method="post">
    <div class="form-group">
        <label class="" for="zip">Zip Code</label>
        <div class="">
            <input autocomplete="postal-code" class="form-control" id="zip" name="zip" placeholder="99999" value="" />
        </div>
    </div>
    <div class="form-group">
        <label class="" for="first_name">First Name</label>
        <div class="">
            <input autocomplete="given-name" class="form-control" type="text" name="first_name" placeholder="First Name"  value=""/>
        </div>
    </div>
    <div class="form-group">
        <label class="" for="last_name">Last Name</label>
        <div class="">
            <input autocomplete="family-name" class="form-control" type="text" name="last_name" placeholder="Last Name"  value="" />
        </div>
    </div>
    <div class="form-group">
        <label class="" for="email">Email</label>
        <div class="">
            <input autocomplete="email" class="form-control" type="email" name="email" placeholder="name@example.com"  value="" />
        </div>
    </div>
    <div class="form-group">
        <label class="<" for="phone">Phone</label>
        <div class="<">
            <input autocomplete="tel" class="form-control" type="tel" name="phone" placeholder="(555) 555-5555"  value="" />
        </div>
    </div>
    <div class="form-group">
        <label class="" for="electric_bill">Electric Bill</label>
        <select class="form-control" id="electric_bill" name="electric_bill" required>
            <option value="">Select Average Monthly Bill</option>
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


    <div class="checkbox">
        <label>
            <input name="additionalServices"  value="Energy Storage / Bright Box Battery" type="checkbox"> I'm interested in Brightbox Solar Battery Storage
        </label>
    </div>
    <div class="checkbox">
        <label>
            <input name="Referral_web_form__c"  value="yes" type="checkbox"> I was referred to Sunrun by a friend or family member
        </label>
    </div>
    <input id="campid" type="hidden" name="campid" value="SRUN-THD-WEB">
    <input type="hidden" name="ret_url" value="https://www.sunrun.com/ty/thank-you">
    <input type="hidden" name="Auto_dialer_Opt_in__c" value="1">
    <input type="hidden" name="Web_User_ID__c" value="">
    <input type="hidden" id="Application_client_id__c" name="Application_client_id__c" value="">
    <input type="hidden" id="retailStoreLocation" name="retailStoreLocation" value="0010d00001Iqa1z">
    <div class="text-center">
        <button type="submit" class="btn btn-cta">Request a free quote</button>
    </div>

    <small class="pageid-tcpa">
        <?php print $tcpa; ?>
    </small>
</form>
