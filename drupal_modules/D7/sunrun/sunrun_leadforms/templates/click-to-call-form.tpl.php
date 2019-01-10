<?php
/**
 * Debugging option
 * <input type="hidden" name="debug" value=1>
 */
?>
<div class="click-to-call-form">
  <form action="<?php print variable_get('ctc_form_action'); ?>" method="POST">

    <input type="hidden" name="oid" value="<?php print variable_get('ctc_form_oid'); ?>">
    <input type="hidden" name="retURL" value="<?php print variable_get('ctc_form_return_url'); ?>">

    <div class="form-row">
      <label for="first_name">First Name</label>
      <input id="first_name"
              maxlength="40"
              name="first_name"
              size="20"
              type="text"
              placeholder="First Name"
              required=true/>
    </div>

    <div class="form-row">
      <label for="last_name">Last Name</label>
      <input id="last_name"
              maxlength="80"
              name="last_name"
              size="20"
              type="text"
              placeholder="Last Name"
              required=true/>
    </div>

    <div class="form-row">
      <label for="phone">Phone</label>
      <input id="phone"
              maxlength="40"
              name="phone" size="20"
              type="text"
              placeholder="(555) 555-5555"
              required=true/>
    </div>


    <div class="hidden">
      <!-- Channel -->
      <input id="00N60000002YDag" name="00N60000002YDag" title="Channel" type="hidden" value="" />

      <!-- Lead source -->
      <input id="00N60000002YDal" name="00N60000002YDal" title="Lead Source" type="hidden" value="" />

      <!-- Keywords -->
      <input  id="00N60000001au5F" maxlength="255" name="00N60000001au5F" size="20" type="hidden" value="" />

      <!-- Content -->
      <input  id="00N600000037ZLs" maxlength="80" name="00N600000037ZLs" size="20" type="hidden" value="" />

      <!-- Technology -->
      <input  id="00N32000002iXJl" name="00N32000002iXJl" size="1" type="hidden" value="Sunrun.com Click-to-Call">

      <!-- Lead Type -->
      <input  id="00N600000037ZLt" name="00N600000037ZLt" size="1" type="hidden" value="Web Capture">

      <!-- Auto-dialer Opt-in: -->
      <input id="00N6000000375eP" name="00N6000000375eP" type="hidden" value="1"/>

      <!-- Consent to call -->
      <input id="00N32000002p2f6" name="00N32000002p2f6" type="hidden" value="Yes">
    </div>

    <input type="submit" name="submit" value="<?php print variable_get('ctc_form_button_text'); ?>" class="btn-orange btn">

  </form>
  <p class='form-autodialer-opt-in'>By clicking above, I authorize Sunrun to call me and send pre-recorded messages and text messages to me about Sunrun products and services at the telephone number I entered above, using an autodialer, even if I am on a national or state "Do Not Call" list. Message and data rates may apply. I understand that consent here is not a condition of purchase.</p>
</div>
