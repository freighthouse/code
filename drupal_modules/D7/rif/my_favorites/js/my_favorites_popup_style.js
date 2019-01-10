Drupal.theme.prototype.add_favorite_theme = function () {
	var html = '';
	html += '<div id="ctools-modal" class="popups-box add-favorite-popup">';
	html += '	<div class="ctools-modal-content add-favorite-popup-content">';
	html += ' 		<div class="modal-header">';
	html += ' 			<span class="popups-close"><a class="close" href="#">' + Drupal.CTools.Modal.currentSettings.closeText + '<span aria-hidden="true">×</span></a></span>';
	html += ' 			<span id="modal-title" class="modal-title"> </span>';
	html += '		</div>';
	html += '		<div class="modal-msg"></div>';
	html += '		<div id="modal-content">';
	html += '		</div>';
	html += ' 	</div>';
	html += '</div>';
	return html;
};
