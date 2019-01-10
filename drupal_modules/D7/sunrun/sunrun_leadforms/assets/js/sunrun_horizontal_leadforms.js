/* globals Drupal, jQuery, labels */


(function($) {
  Drupal.behaviors.sunrun_horizontal_leadforms = {
    attach: function(context, settings) {

  		// Use the labels for the horizontal forms
      $('.form-horizontal .form-group').each(function(){
        var fhLabel = $(this).find('label').text();
        var fhinput = $(this).find('input');
        if(fhinput.attr('placeholder')){
          fhinput.attr('placeholder', fhLabel);
        }
      });  

    }//attach
  };//Drupal.behaviors.sunrun_horizontal_leadforms

}(jQuery));
