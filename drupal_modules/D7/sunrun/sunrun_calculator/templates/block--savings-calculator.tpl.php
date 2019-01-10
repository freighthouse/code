<div class="savings-wrapper savings-calculator">
    <div class="step initial">
        <div class="blur-overlay">
            <img src="/sites/default/themes/sunrun/public/assets/images/sunrun-loader.gif" class="progress-indicator"
                 alt="">
        </div>
        <div class="map-results obscurable obscured">
            <!-- <div class="calculation-overlay no-address-hide"><img src="/sites/default/themes/sunrun/public/assets/images/sunrun-loader.gif" alt=""></div> -->
            <div class="row header-container">
                <div class="col-sm-6 map-canvas">
                    <div class="map"></div>
                    <div class="overlay-address hide"><img
                                src="/sites/default/themes/sunrun/public/assets/svg/location-pin.svg"
                                alt=""/><span></span></div>
                </div>
                <div class="col-sm-6 results">

                    <div class="no-address-input">
                        <h2>See Your Solar Savings</h2>
                        <form action="calculator" method="get" autocomplete="off" onsubmit="return calculateSubmit();">
                            <div class="form-group">
                                <input type="hidden" name="street_number" id="street_number">
                                <input type="hidden" name="route" id="route">
                                <input type="hidden" name="locality" id="locality">
                                <input type="hidden" name="administrative_area_level_1"
                                       id="administrative_area_level_1">
                                <input type="hidden" name="country" id="country">
                                <input type="hidden" name="postal_code" id="postal_code">
                                <input type="text" class="form-control" name="address" autocomplete="new-password"
                                       id="address-autocomplete" placeholder="Enter address">
                                <button class="btn btn-cta" id="calculate-submit" disabled>See Savings</button>
                            </div>
                        </form>
                    </div>

                    <div class="bill-wrapper disable no-address-hide obscurable obscured">
                        <h2>Current Monthly Electric Bill</h2>
                        <p>Select your bill amount to see how much solar can save you</p>
                        <div class="bill-slider">
                            <input type="range" min="50" max="550" step="50" value="250">
                        </div>
                    </div>

                </div>
            </div>
        </div>

        <div class="inner">
            <div class="calculator-results obscurable obscured">
                <div class="message">
                    <h1 class="blue">See how much you can save by going solar with Sunrun!</h1>
                </div>
                <ul class="features blue">
                    <li class="property-size">
                        <div class="icon-wrapper"><img
                                    src="/sites/default/themes/sunrun/public/assets/svg/property-size.svg" alt=""></div>
                        Property Size<span></span></li>
                    <li class="electric-cost">
                        <div class="icon-wrapper"><img
                                    src="/sites/default/themes/sunrun/public/assets/svg/electric-cost.svg" alt=""></div>
                        Pre-Solar 20 Year Electric Cost<span></span></li>
                    <li class="home-value-increase">
                        <div class="icon-wrapper"><img
                                    src="/sites/default/themes/sunrun/public/assets/svg/home-value-increase.svg" alt="">
                        </div>
                        Home Value Increase^<span></span></li>
                    <li class="trees-planted">
                        <div class="icon-wrapper"><img
                                    src="/sites/default/themes/sunrun/public/assets/svg/trees-planted.svg" alt=""></div>
                        Trees Planted<span></span></li>
                </ul>
                <!-- <i class="icon icon-chevron-down"></i> -->
                <div class="address-input-copy">
                    <p></p>
                </div>
            </div>
        </div>

    </div>
</div>
