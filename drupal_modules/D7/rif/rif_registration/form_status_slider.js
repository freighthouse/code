/*
 * Fix sidebar at some point and remove
 * fixed position at content bottom
 */

jQuery(document).ready(
	function($) {

		// Load the Are You Sure Messaging Script
		jQuery.getScript('/sites/all/libraries/are_you_sure/jquery.are-you-sure.js', function()
		{
			var $form = jQuery('.node-form');
			console.log($form);
			var $draftButton = jQuery('#edit-draft');

			var $errorMessages = $('#modal-messages .messages.error');
			console.log($errorMessages);
			if($errorMessages[0]) {
				console.log("Dirty up the form");
				$form.addClass('dirty dirty-persistent');
			}

			$form.areYouSure( { message: 'Do you really want to exit?.', dirtyClass: 'unsaved' } );
			if (!$form.hasClass('dirty')) {
				$draftButton.attr('disabled', 'disabled').attr('value','Draft Saved');
			}
			$form.on('dirty.areYouSure', function() {
				// Enable save button only as the form is dirty.
				$draftButton.removeAttr('disabled').attr('value','Save Draft');
				console.log("on Dirty");
			});
			$form.on('clean.areYouSure', function() {
				// Form is clean so nothing to save - disable the save button.
				if($form.hasClass('dirty-persistent')) {
					return;
				}
				$draftButton.attr('disabled', 'disabled').attr('value','Draft Saved');
				console.log("on Clean");
			});
		});

		// Set up the Floating Form Status Menu
		var $floatingMenu = jQuery('.pane-rif-registration-form-status-single-site');
		var triggerHeight = $floatingMenu.offset().top - 60;
		var floatingMenuInitialWidth = $floatingMenu.width();
		var floatingMenuMaxHeight = $floatingMenu.closest('.row').height(); - $floatingMenu.height();
		var rowOffset = $floatingMenu.closest('.row').offset().top;
		function refreshValues() {
			floatingMenuInitialWidth = $floatingMenu.parent().width();
			floatingMenuMaxHeight = $floatingMenu.closest('.row').height(); - $floatingMenu.height();
			$floatingMenu.css({'width' : floatingMenuInitialWidth});
		}
		jQuery(window).resize( refreshValues );
		jQuery(window).scroll(function () {
			var displacement = jQuery(window).scrollTop() - triggerHeight;
			if(displacement < 0) { displacement = 0; }
			if (jQuery(window).scrollTop() >= triggerHeight && jQuery(window).scrollTop() <= floatingMenuMaxHeight) {
				$floatingMenu.addClass('fixed');
				$floatingMenu.css({'width' : floatingMenuInitialWidth, 'top': 60});
				//console.log("FIRE add Fxied");
			} else {
				$floatingMenu.removeClass('fixed');
				if(jQuery(window).scrollTop() >= floatingMenuMaxHeight) {
					//console.log('magic');
					$floatingMenu.css({'top' : floatingMenuMaxHeight-rowOffset-60});
				} else {
					$floatingMenu.css({'top' : 0});
				}
				$floatingMenu.css({'width' : floatingMenuInitialWidth});
			}
		});
	}
);

