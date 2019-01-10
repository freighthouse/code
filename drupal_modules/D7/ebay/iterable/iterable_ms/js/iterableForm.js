jQuery(function(){
  
  var email = iterableUtils.getCookie('iterableEndUserId');
  var uri = "";

  if (email && email.length != 0) {
    jQuery('#content-iterable-ms-manage-subscription').show();
    jQuery('#block-iterable-ms-manage-subscription').show();
    uri = "/iterable/get/ajax/subscription/" + email;
    jQuery('#content-iterable-ms-manage-subscription').load(uri, function(){

      jQuery('.phone-checkbox').change(function(){
        jQuery('.form-item-phone').hide();
        jQuery('.phone-checkbox').each(function(){
          if (this.checked) jQuery('.form-item-phone').show();
        });
      });

      jQuery('.form-item-phone').hide();
      jQuery('.phone-checkbox').each(function(){
        if (this.checked) jQuery('.form-item-phone').show();
      });

    });
  }

});