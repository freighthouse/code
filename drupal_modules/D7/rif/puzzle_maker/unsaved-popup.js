/**
 * Created by gshingler on 12/6/17.
 */
jQuery(document).ready(
	function($) {
		// Load the Are You Sure Messaging Script
		jQuery.getScript('/sites/all/libraries/are_you_sure/jquery.are-you-sure.js', function(){
			var $form = jQuery('.node-form');

			$form.areYouSure( { message: 'Do you really want to exit?.', dirtyClass: 'unsaved' } );
			// var $draftButton = jQuery('#edit-draft');
			//
			var $errorMessages = $('#modal-messages .messages.error');
			$form.find('#edit-cancel').click(function(event){
				if(!confirm("Are you sure you want to leave? Any unsaved changes will be lost?")){
					return false;
				}
			}) ;

			if($errorMessages[0]) {
				$form.addClass('unsaved unsaved-persistent');
			}
			if($form.hasClass('unsaved-persistent')){
				$form.addClass('unsaved');
			}
			$form.on('clean.areYouSure', function() {
				if($form.hasClass('unsaved-persistent')) {
					$form.addClass('unsaved');
				}
			});
		});

		var $form_dest = $('#preview-form-replacement');
		var $form_source = $('.preview-form-to-move');

		if($form_source.length > 0) {
			$form_source.find('.rif-banner').appendTo(jQuery('.region.region-navigation'));
			$form_dest.append($form_source);
			$form_dest.find('.col-sm-offset-3').removeClass('col-sm-offset-3');
			$form_dest.find('.col-sm-9').removeClass('col-sm-9');
		}
	}
);