Drupal.theme.prototype.add_lt_group_theme = function () {
	var html = '';
	html += '<div id="ctools-modal" class="popups-box lt-popup-box">';
	html += '	<div class="ctools-modal-content add-favorite-popup-content">';
	html += ' 		<div class="modal-header">';
	html += '				<span class="close popups-close" data-dismiss="modal" aria-label="Close" style="opacity:1">' + Drupal.CTools.Modal.currentSettings.closeText + '<span aria-hidden="true">×</span></span>';
	// html += ' 			<span class="popups-close"><a class="close" href="#">' + Drupal.CTools.Modal.currentSettings.closeText + '<span aria-hidden="true">×</span></a></span>';
	html += ' 			<span id="modal-title" class="modal-title"> </span>';
	html += '		</div>';
	html += '		<div class="modal-msg"></div>';
	html += '		<div id="modal-content">';
	html += '		</div>';
	html += ' 	</div>';
	html += '</div>';
	return html;
};
