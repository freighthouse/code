<div id="srPurlsUserNameDetailsWrapper" class="purl-user-info-container">
    <h3>Name</h3>
    <div class="change-link">
        <a href="ajax-purls-request/change/name/details" id="srPurlsChangeName" class="use-ajax">Change</a>
    </div>
    <div id="srPurlsUserNameDetails" class="user-details clearfix">
        <div class="name"><?php echo $user->first; ?> <?php echo $user->last; ?></div>
    </div>
    <h3>Address</h3>
    <div class="change-link">
        <a href="ajax-purls-request/change/address/details" id="srPurlsChangeAddress" class="use-ajax">Change</a>
    </div>
    <div id="srPurlsUserAddressDetails" class="user-details clearfix">
        <div class="street"><?php echo $user->address; ?></div>
        <div class="city-state"><?php echo $user->city; ?>, <?php echo $user->state; ?></div>
        <div class="zip"><?php echo $user->zip; ?></div>
    </div>
    <!--<input type="range" value="<?php echo $user->bill; ?>" min="0" max="350" step="1">-->
</div>
<div class="get-quote-form">
    <script src="<?php echo $environment; ?>/js/forms2/js/forms2.min.js"></script>
    <form id="mktoForm_<?php echo $form_id; ?>"></form>
</div>
