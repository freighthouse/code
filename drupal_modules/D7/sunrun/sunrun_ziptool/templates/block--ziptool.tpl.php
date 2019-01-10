<div class="ziptool-wrapper">
  <div class="form-container">
    <form class="ziptoolForm mktoHasWidth mktoLayoutLeft" method="get" novalidate>
      <!-- step 1 -->
      <div class="formRow step-1 current">
        <fieldset class="mktoFormCol">
          <legend></legend>
          <div class="formRow">
            <div class="mktoFormCol">
              <div class="mktoFieldWrap">
                  <h3>Your City <a class="edit js-zip-edit edit-link"><span class="glyphicon glyphicon-pencil" aria-hidden="true"></span></a></h3>
                  <div class="supporting-text">
                    <p class="help-block">See if we're in your area</p>
                    <p class="city-state"></p>
                  </div>
                <div class="form-group">
                  <input type="text" placeholder="Enter zip code" maxlength="6" name="zipcode" id="zipcode" autofocus>
                  <div class="mktoButtonRow">
                    <button class="next btn btn-orange">Check my zip code &#10095;</button>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </fieldset>
      </div>
      <div class="divider"></div>
      <!-- step 2 -->
      <div class="formRow step-2">
        <fieldset class="mktoFormCol">
          <legend></legend>
          <div class="formRow">
            <div class="mktoFormCol">
              <div class="mktoFieldWrap">
                <h3>Your Bill <a class="edit js-zip-edit edit-link"><span class="glyphicon glyphicon-pencil" aria-hidden="true"></span></a></h3>
                <div class="supporting-text">
                  <p class="bill-amount"></p>
                  <p class="help-block">What's your average monthly electric bill?</p>
                  <p class="bill-review">Actually that's not bad.</p>
                </div>
                <div class="form-group">
                  <input type="text" placeholder="Enter amount" name="Bill" id="Bill">
                  <div class="mktoButtonRow">
                    <button class="next btn btn-orange">Check my bill &#10095;</button>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </fieldset>
        <img class="arrow" src="<?php print drupal_get_path('module', 'sunrun_ziptool'); ?>/assets/images/active_arrow.png" alt="active arrow">
      </div>
      <div class="divider"></div>
      <!-- step 3 -->
      <div class="formRow step-3">
        <fieldset class="mktoFormCol">
          <legend></legend>
          <div class="formRow">
            <div class="mktoFormCol">
              <div class="mktoFieldWrap">
                <h3>Your Street <a class="edit js-zip-edit edit-link"><span class="glyphicon glyphicon-pencil" aria-hidden="true"></span></a></h3>
                <div class="supporting-text">
                  <p class="help-block">What's your street address?</p>
                </div>
                <div class="form-group">
                  <input type="text" placeholder="Enter street address" name="ziptoolStreet" id="ziptoolStreet">
                  <div class="mktoButtonRow">
                    <button class="next btn btn-orange">Check my address &#10095;</button>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </fieldset>
        <img class="arrow" src="<?php print drupal_get_path('module', 'sunrun_ziptool'); ?>/assets/images/active_arrow.png" alt="active arrow">
      </div>
      <!-- step-4 -->
      <div class="formRow row step-4">
        <fieldset class="mktoFormCol">
          <legend></legend>

          <h3>A few more questions:</h3>

          <div class="formRow">
            <p>Choose your roof type:</p>
            <div class="radio">
              <label>
                <input type="radio" name="roof" id="roof1" value="shingle"> shingle
              </label>
            </div>
            <div class="radio">
              <label>
                <input type="radio" name="roof" id="roof2" value="tile" checked> tile
              </label>
            </div>
            <div class="radio">
              <label>
                <input type="radio" name="roof" id="roof3" value="other"> other
              </label>
            </div>
          </div>
          <div class="formRow">
            <p>How much shade does your roof get?</p>
            <div class="radio">
              <label>
                <input type="radio" name="shade" id="shade1" value="max"> a lot
              </label>
            </div>
            <div class="radio">
              <label>
                <input type="radio" name="shade" id="shade2" value="mid" checked> a little
              </label>
            </div>
            <div class="radio">
              <label>
                <input type="radio" name="shade" id="shade3" value="min"> none
              </label>
            </div>
          </div>

          <div class="mktoButtonRow">
            <button class="next btn btn-orange">Show me my rating &#10095;</button>
          </div>

        </fieldset>
      </div>
    </form>

    <div id="map-container" class="ziptool-content-panel">
      <div id="map"></div>
    </div>

  </div>

  <div id="ziptool-out-of-area" class="ziptool-content-panel row">
    <div class="col-sm-8">
      <h3>Sunrun is not currently in your area yet.</h3>

      <p>However, our partner, Solar America, may be able to help you find a qualified solar company that services your neighborhood. <a href="http://www.solaramerica.org/" target="_blank">Click here</a> to leave Sunrun's website and visit Solar America.</p>

    </div>
  </div>

</div>
