jQuery(document).ready(function($) {
  // validate signup form on keyup and submit
  
  $("#signup-form").validate({
    rules: {
      firstName: "required",
      lastName: "required",
      timezonepkey: "required",
      AccountCountry: "required",
      userName: {
        required: true,
        minlength: 3,
        maxlength: 12
      },
      password: {
        required: true,
        minlength: 5
      },
      passwordConfirm: {
        required: true,
        minlength: 5,
        equalTo: "#password"
      },
      email: {
        required: true,
        email: true
      },
      phoneNumber: {
        required: true,
        phoneUS: true
      },
      phoneNumberConfirm: {
        required: true,
        phoneUS: true,
        equalTo: "#phoneNumber"
      }
    },
    messages: {
      firstName: "Please enter your first name",
      lastName: "Please enter your last name",
      timezonepkey: "Please select your time zone",
      AccountCountry: "Please select the country you will be texting to",
      email: {
        required: "Please enter a valid email address",
        minlength: "Please enter a valid email address",
      },
      userName: {
        required: "Please enter a username",
        minlength: "Your username must consist of at least 2 characters"
      },
      password: {
        required: "Please provide a password",
        minlength: "Your password must be at least 5 characters long"
      },
      passwordConfirm: {
        required: "Please provide a password",
        minlength: "Your password must be at least 5 characters long",
        equalTo: "Please enter the same password as above"
      },
      phoneNumber: {
        required: "Please enter a valid phone number",
        phoneUS: "Please enter a valid phone number"
      },
      phoneNumberConfirm: {
        required: "Please enter a valid phone number",
        phoneUS: "Please enter a valid phone number",
        equalTo: "The numbers you have entered do not match, please renter the number"
      }
    },
    highlight: function(element) {
      $(element).closest('.form-group').addClass('has-error');
    },
    unhighlight: function(element) {
      $(element).closest('.form-group').removeClass('has-error');
    }
  });
});