jQuery(document).ready(function($) {
    $('form#-ebay-custom-bipac-join-form').bind('state:visible', function(e) {
        if(e.trigger) {
            $(e.target).closest('.form-item, .form-submit, .form-wrapper')[e.value ? 'fadeIn' : 'fadeOut']();
            e.stopPropagation();
        }
    });
});
