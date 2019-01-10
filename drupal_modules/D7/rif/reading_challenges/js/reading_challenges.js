(function ($, global) {
	$(document).ready(function () {
		// Parse the reading passage body text into the clickable elements
		var e = document.getElementById('words');
		var t = document.getElementById('edit-words-clicked');

		e.innerHTML = e.innerHTML.replace(/(^|<\/?[^>]+>|\s+)([^\s<]+)/g, '$1<span class="word">$2</span>');

		e.addEventListener('click', function (ev) {
			if (ev.target.classList.contains('word')) {
				ev.target.classList.toggle('highlighted');
				$(t).val(e.querySelectorAll('.highlighted').length);
			}
		}, true);

		var min_time = 30000;// 30,000 ms = 30s = 0.5 minutes
		var max_time = 900000; // 900,000 ms = 900 seconds = 15 minutes

// Referenced Code From: https://www.w3schools.com/howto/howto_js_countdown.asp

// Set the date we're counting down to
		var start_date = new Date().getTime();
		var distance = 0;

// Update the count down every 1 second
		var x = setInterval(function () {

			// Get today's date and time
			var now = new Date().getTime();

			// Find the distance between now an the count down date
			distance = now - start_date;

			// Time calculations for days, hours, minutes and seconds
			// var days = Math.floor(distance / (1000 * 60 * 60 * 24));
			// var hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
			var minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
			var seconds = Math.floor((distance % (1000 * 60)) / 1000);

			// Display the result in the element with id="demo"
			jQuery(".timer-counter .minutes").html(pad(minutes, 2));
			jQuery(".timer-counter .seconds").html(pad(seconds, 2));

			// If the count down is finished, write some text
			if (distance >= max_time) {
				clearInterval(x);
				jQuery(".timer-container").html("<p>Oops! It’s been 15 minutes and we cannot get an accurate score for this attempt. Try again! <br><a class=\"btn btn-blue launch-btn\" href=\"/literacy-tracker/student/reading-challenge\">New Reading Challenge</a></p>");
				//document.getElementById("demo").innerHTML = "EXPIRED";
			}
		}, 1000);
    
		function pad(str, max) {
			str = str.toString();
			return str.length < max ? pad("0" + str, max) : str;
		}

		var $form_button = $(".reading-challenge-form #edit-submit");
		$form_button[0].addEventListener('click', function (ev) {
			if(distance < min_time) {
				$('#modal-that-was-fast').modal('show');
				event.preventDefault();
			}
		}, true);

		var $modal_button = $('#modal-confirm');
		$modal_button[0].addEventListener('click', function(ev){
			distance = min_time;
			$form_button.click();
		}, true);

	});
})(jQuery, window);
