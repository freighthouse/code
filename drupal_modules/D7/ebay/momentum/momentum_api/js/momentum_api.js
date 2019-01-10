jQuery(document).ready(function($) {
	if ( $( "#editable" ).length ) {
		CKEDITOR.replace( "editable", {
			height: 550,
			toolbarGroups: [
				{"name":"clipboard","groups":["clipboard"]},
			]
		});
	}
	if ( $( "#partial" ).length ) {
		CKEDITOR.replace( "partial", {
			toolbarGroups: [
				{"name":"clipboard","groups":["clipboard"]},
			]
		});
	}
		
	function parse_data(text,partial){
		var prefix=$('#edit-writer-prefix option:selected').text();
		var first=$('#edit-writer-first-name').val();
		var last=$('#edit-writer-last-name').val();
		var address1=$('#edit-writer-address-1').val();
		//var address2=$('#edit-writer-address-2').val();
		var city=$('#edit-writer-city').val();
		var state=$('#edit-writer-state option:selected').text();
		var zip=$('#edit-writer-zip').val();
		var phone=$('#edit-writer-phone').val();
		var email=$('#edit-writer-email').val();
		//var address= address1+" "+address2+" "+city+", "+state+" "+zip;
		
		var newText = text.replace(/\|first\|/g, first);
		
		
		
		newText = newText.replace(/\|prefix\|/g, prefix);
		newText = newText.replace(/\|last\|/g, last);
		newText = newText.replace(/\|state\|/g, state);
		newText = newText.replace(/\|city\|/g, city);
		newText = newText.replace(/\|address\|/g, address1);
		newText = newText.replace(/\|phone\|/g, phone);
		newText = newText.replace(/\|email\|/g, email);
		newText = newText.replace(/\|zip\|/g, zip);
		newText = newText.replace(/\|Please share a personal story\|/g, partial);
		
		return newText;
	}
	
	$('.preview_letter_partial').click(function(event)
	{
			event.preventDefault();
			event.stopPropagation();
			var newText="";
			var partial="";
			//Gets the original 
			var original=$(this).parent().children(".letter_original").html();
			
			//partial text to add
			partial=$("#partial").val();
			//parse the text
			newText=parse_data(original,partial);
			$(this).parent().children(".letter_message_partial").html(newText);
			
			
		});
	$('.preview_letter_static').click(function(event)
	{
			event.preventDefault();
			event.stopPropagation();
			var newText="";
			var partial="";
			//Gets the original 
			var original=$(this).parent().children(".letter_original").html();
	
			//parse the text
			newText=parse_data(original,partial);
			$(this).parent().children(".letter_message_static").html(newText);
		});
	
	function validate_form(){
		var zip_code=$('#edit-writer-zip').val();
		var clean = zip_code.replace(/[^\d]/g, '');
		var reg = /^[0-9]+$/;
		var errorMessage ="";
		if (zip_code === ''){
			errorMessage = "Zipcode field is required.";
		}
		else if ((zip_code.length)< 5  ){
			errorMessage = "Zipcode should have at least 5 digits.";
		}
		else if (!reg.test(zip_code)){
			errorMessage = "Zipcode should be numbers only.";
		}
		$('#edit-writer-zip').val(clean);

		if(errorMessage!==""){
			//create the field if it doesnt exists.

			$("div.form-item-writer-zip label.error").show().text(errorMessage);}
		else{$("div.form-item-writer-zip label.error").hide().text("Zipcode field is required");}


		var phone = $('#edit-writer-phone').val();
		clean = phone.replace(/[^\d]/g, '');
		reg = /^[0-9]+$/;
		if (phone === ''){
			errorMessage = "Phone Number required!";
		}
		else if ((phone.length)< 10  ){
			errorMessage = "*Phone number should have at least 10 digits";
		}
		else if (!reg.test(phone)){
			errorMessage = "*Phone number should be numbers only";
		}
		$('#edit-writer-phone').val(clean);
		 if(errorMessage!==""){
			$("div.form-item-writer-phone label.error").show().text(errorMessage);}
		else{$("div.form-item-writer-phone label.error").hide().text("Phone number field is required");
		}


		var mail = $('#edit-writer-email').val();
		reg = /^([\w-\.]+)@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.)|(([\w-]+\.)+))([a-zA-Z]{2,4}|[0-9]{1,3})(\]?)$/;
		if (mail === ''){
			errorMessage = "*E-mail Address required!";
		}
		else if ((mail.length)< 10  ){
			errorMessage = "*E-mail Address should have at least 10 characters";
		}
		else if (!reg.test(mail)){
			errorMessage = "*Email address format is invalid";
		}
		
		if(errorMessage!==""){
			$("div.form-item-writer-email label.error").show().text(errorMessage);
		}

		else{$("div.form-item-writer-email label.error").hide();}
		return errorMessage;
	}
	
	$("button.ladda-button").click(function(){
		
		var errorMessage =validate_form();
		if(errorMessage==""){
			$("form#-bipac-campaigns-bipac-letter-form").submit();
			}
		else{
			alert(errorMessage);
		}
		});
	
	$("form#-bipac-campaigns-bipac-letter-form").submit(function(){
		var errorMessage =validate_form();
		if(errorMessage!==""){
			$("div.form-item-writer-email label.error").show().text(errorMessage);
			return false;}

		else{$("div.form-item-writer-email label.error").hide().text("Email field is required");
		return true;}

	});

	$('#edit-writer-zip').blur(function() {
		var zip_code=$('#edit-writer-zip').val();
		if(zip_code!==""){
		$.ajax({
					  dataType: "json",
					  url: '/zip/retreive',
					  type: 'GET',
					  data: {
						  zip: zip_code,
					  },
					  success: function(data) {
						  if(typeof(data[zip_code])!=='undefined'){
							  $('#edit-writer-city').val(data[zip_code].city);
							  $('#edit-writer-state').val(data[zip_code].state);
						  }
					  },
					  error: function(e) {
						return false;
					  }
					});
		}

	});
	$('#letter_select').change(function(){
		$('.letter:visible').slideUp(200, function(){
			var id=$('#letter_select').val();
			$("#"+id).slideDown(500);
		});
	});

	$('#momentum_report').click(function(event) {
		event.preventDefault();
    	event.stopPropagation();

		var report_type=$('#edit-report').val();
		var id=$('#edit-campaigns').val();

		var strt_day=$('#edit-start-date-day').val();
		var strt_mnt=$('#edit-start-date-month').val();
		var strt_yr=$('#edit-start-date-year').val();
		var strt="";
		var end_day=$('#edit-end-date-day').val();
		var end_mnt=$('#edit-end-date-month').val();
		var end_yr=$('#edit-end-date-year').val();
		var end="";
		
		
		if(strt_day!=="0"){
			strt=strt_yr+"-"+strt_mnt+"-"+strt_day;
		}
		if(end_day!=="0"){
			end=end_yr+"-"+end_mnt+"-"+end_day;
		}
		
		var params = { };
		params.id = id;
		params.datestart=strt;
		params.dateend=end;

		// Will create the JSON string you're looking for.
		var paramsjson = JSON.stringify(params);

		console.log (paramsjson);

		if(report_type!==""){
		$.ajax({
					  dataType: "json",
					  url: '/admin/config/system/momentum/reports/data',
					  type: 'GET',
					  data: {
						  report: report_type,
						  parameters:paramsjson,
					  },
					  success: function(data) {
						  console.log (data);
						  $("#report_table").html(data);
					  },
					  error: function(e) {
						return false;
					  }
					});
		}
		 return false;
	});


});