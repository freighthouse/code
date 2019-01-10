<div class="cap-box-top">
    <h3 class="pane-subtitle">See if you qualify</h3>
    <h4 class="pane-tabtitle">Go solar in 3 easy steps</h4>
</div><!-- //cap-box-top -->
<div class="cap-box-bottom">
    <!-- progressbar -->
    <form id="multi-step-form" method="post" autocomplete="on" action="#" novalidate="novalidate">
        <ul id="progressbar" class="progressbar">
            <li class="active"><span>1</span></li>
            <li><span>2</span></li>
            <li><span>3</span></li>
        </ul>
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
                <label for="zip"></label>
                <input value="" placeholder="Zip Code" maxlength="5" name="zip" id="zip" class="form-control"
                       autocomplete="postal-code">
            </div>
            <div class="text-center btn-block">
                <button class="btn btn-orange next action-button" type="button" name="next">Next ></button>
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
            <div class="text-center btn-block">
                <button class="btn btn-orange next action-button" type="button" name="next">Next ></button>
            </div>
        </fieldset>
        <fieldset>
            <legend class="field-title"></legend>
            <div class="form-group">
                <input type="text" value="" placeholder="First Name" name="first_name" class="form-control"
                       autocomplete="given-name">
            </div>
            <div class="form-group">
                <input type="text" value="" placeholder="Last Name" name="last_name" class="form-control"
                       autocomplete="family-name">
            </div>
            <div class="form-group">
                <input type="tel" value="" placeholder="(555) 555-5555" name="phone" class="form-control"
                       autocomplete="tel">
            </div>
            <div class="form-group">
                <input type="email" value="" placeholder="name@example.com" name="email" class="form-control"
                       autocomplete="email">
            </div>
            <div class="checkbox">
                <label>
                    <input name="additionalServices" value="Energy Storage / Bright Box Battery" type="checkbox"> I'm
                    interested in Brightbox Solar Battery Storage
                </label>
            </div>
            <div class="checkbox">
                <label>
                    <input name="Referral_web_form__c" value="yes" type="checkbox"> I was referred to Sunrun by a friend
                    or family member
                </label>
            </div>

            <input id="campid" type="hidden" name="campid" value="">
            <input type="hidden" id="default_campid" name="default_campid" value="B08051BC1B15C238">
            <input type="hidden" name="Auto_dialer_Opt_in__c" value="1">
            <input type="hidden" name="technology" value="multistep">
            <input type="hidden" name="Web_User_ID__c" value="">
            <input type="hidden" id="Application_client_id__c" name="Application_client_id__c" value="">
            <div class="text-center btn-block">
                <button class="btn btn-orange submit action-button" type="submit" name="submit">Submit</button>
            </div>
            <small class="pageid-tcpa">
                <?php print $tcpa; ?>
            </small>
        </fieldset>
    </form>
    <div class="thank-you">
        <p class="in-service-msg">Thanks so much! We'll call you shortly.</p>
        <p class="out-of-service-msg"><?php print $oot_msg; ?></p>
        <p>
            &nbsp;
        </p>
        <a href="/referral" target="_blank" class="refer-friend-block"></a><!-- //refer-friend-block -->
        <a href="/referral" class="btn btn-blue" target="_blank" style="">Refer a friend and get $350</a>
    </div>
</div><!-- //cap-box-bottom -->
