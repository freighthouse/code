<?php

/**
* @file
* Customize the display of a complete webform.
*
* This file may be renamed "webform-form-[nid].tpl.php" to target a specific
* webform on your site. Or you can leave it "webform-form.tpl.php" to affect
* all webforms on your site.
*
* Available variables:
* - $form: The complete form array.
* - $nid: The node ID of the Webform.
*
* The $form array contains two main pieces:
* - $form['submitted']: The main content of the user-created form.
* - $form['details']: Internal information stored by Webform.
*/
?>
<?php
// Print out the main part of the form.
// Feel free to break this up and move the pieces within the array.

// Always print out the entire $form. This renders the remaining pieces of the
// form that haven't yet been rendered above.

foreach($form['submitted'] as $key=>$value){
	if(substr($key, 0, 1)<>'#'){
		if ($value["#webform_component"]["type"] != 'hidden') {
			$fixLabelFor = preg_replace('/\ +/', '-', $key);
			$prefix = '<div class="form-group">';
			$prefix .= '<label for="edit-submitted-'.$fixLabelFor.'" class="control-label">'.$value['#title'].'</label>';
			$prefix .=  ' <small class="text-muted">'.$value['#description'].'</small>';

			$suffix = '</div>';

			$form['submitted'][$key]['#prefix'] = $prefix;
			$form['submitted'][$key]['#suffix'] = $suffix;
			unset($form['submitted'][$key]['#title']);
			unset($form['submitted'][$key]['#description']);
		}
	}
}
print '<div class="col-md-6">';
	print drupal_render($form['submitted']);
	print drupal_render_children($form);
print '</div>';