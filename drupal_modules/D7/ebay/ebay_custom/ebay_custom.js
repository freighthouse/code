jQuery(document).ready(function($) {
  $('#edit-country').change(function() {
    $.ajax({
      url: '/join/' + $(this).val() + '/ajax',
	      success: function(form) {
	        $('#new-form-div').html(form);
	        $('.form-item-control-email').css('display', 'none');
	        $('input[value="Go"]').css('display', 'none');
        }
    });
  });
	
	$('#ebay-custom-join-form').submit(function(event) {
    $.ajax({
      url: '/join/' + $('#edit-country').val() + '/ajax',
	      success: function(form) {
	        $('#new-form-div').html(form);
	        $('.form-item-control-email').css('display', 'none');
	        $('input[value="Go"]').css('display', 'none');
        }
    });
		event.preventDefault();
  });

  $('input#edit-phone, input#edit-phone-2').blur(function() {
    var value = $(this).val();
    var clean = value.replace(/[^\d]/g, '');
    $(this).val(clean);
  });
});

