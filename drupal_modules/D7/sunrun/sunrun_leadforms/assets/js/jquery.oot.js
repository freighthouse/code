(function($) {
  Drupal.behaviors.sunrun_leadforms_multi_step = {
    attach: function(context, settings) {

/* Update page when zip is out of territory */
  		if ($.cookie("sr_oot")){
  				$(".thank-you-out-of-territory-msg").show();
  				$(".bean-hero-banner, .pane-node-body > .pane-content").hide();
  		}
  		else {
  				$(".thank-you-out-of-territory-msg").hide();
  		}
    }
  };

}(jQuery));
