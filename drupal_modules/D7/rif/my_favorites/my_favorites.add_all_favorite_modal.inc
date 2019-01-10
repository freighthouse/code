<?php

	function my_favorites_add_all_callback($js = NULL, $book_id, $nids = NULL) {
		if ($book_id == NULL) {
			return 'NO book nid was sent. Error';
		}

		if ($nids == NULL) {
			return 'No SM nid provided Erroring';
		}

		// Checking JavaScript is enabled.
		if (!$js) {
			//drupal_exit();
			//return;
			// If JavaScript is disabled — outputting content without the popup.
			//$alias = drupal_get_path_alias($nid);
			drupal_goto("/node/".$book_id->nid);
			//return drupal_get_form('my_favorites_add_favorite_form', $node_to_add);
		}
		ctools_include('ajax');
		ctools_include('modal');

		$form_state = array(
			'ajax' => TRUE,
			'title' => t('Add Resources to My Favorites'),
		);

		// Use ctools to generate ajax instructions for the browser to create
		// a form in a modal popup.
		// Use [ctools_modal_command_display(t('My first popup'), $popup_content);] If it is just content with no form
		$form_state['build_info']['args'] = array($book_id->nid, $nids);
		$output = ctools_modal_form_wrapper('my_favorites_add_all_favorite_form', $form_state);
		// If the form has been submitted, there may be additional instructions
		// such as dismissing the modal popup.
		if (!empty($form_state['ajax_commands'])) {
			$output = $form_state['ajax_commands'];
		}

		// Return the ajax instructions to the browser via ajax_render().
		print ajax_render($output);
		drupal_exit();
	}

	/* ****************************************
	 * 			Add Favorite Form
	 * **************************************** */
	function my_favorites_add_all_favorite_form($form, $form_state, $book_id, $nids) {

		$sm_nodes_to_add = explode("_", $nids);

		// Build Favorite Folder List
		$type = 'favoritesfolder';
		$favorite_folder_ids = [];
		global $user;
		$result = FALSE;
		$query = new EntityFieldQuery;
		$result = $query
			->entityCondition('entity_type', 'node')
			->propertyCondition('status', 1)
			->propertyCondition('type', $type)
			->propertyCondition('uid', $user->uid)
			->execute();

		foreach($result['node'] as $pos => $folder) {
			$temp_node = node_load($pos);
			$favorite_folder_ids[$folder->nid] = $temp_node->title;
		}
		$favorite_folder_ids[0] = 'Create New List';

		$emw_book = entity_metadata_wrapper('node', $book_id);
		$bookCoverFileName = file_create_url('public://placeholder263by180.png');
		if(!empty($emw_book->field_book_cover_file_name->value())) {
			$book_cover_filename =$emw_book->field_book_cover_file_name->value();
			$book_cover_uri = 'public://Book_Covers/'.$book_cover_filename;
			if(file_exists($book_cover_uri)) {
				$file_url = file_create_url($book_cover_uri);
				$bookCoverFileName = $file_url;
			}
		}

		$book_title = $emw_book->label();
		$sm_count = sizeof($sm_nodes_to_add);
		$is_plural_text = ($sm_count == 1) ? '' : 's';


		// Build Description Markup
		$description_markup = '';
		$description_markup .= '<div class="support-materials-to-add-container">';
		// Removed because of complexity
		/*$description_markup .= '	<div>';
		$description_markup .= '		<div class="book-cover-container">';
		$description_markup .= '			<img src="'.$bookCoverFileName.'">';
		$description_markup .= '		</div>';
		$description_markup .= '		<div class="book-title">';
		$description_markup .= '			'.$book_title;
		$description_markup .= '		</div>';
		$description_markup .= '	</div>';*/
		$description_markup .= '	<ol>';
		foreach($sm_nodes_to_add as $index => $sm_id) {
			$emw_sm = entity_metadata_wrapper('node', $sm_id);
			$sm_title = $emw_sm->label();
			//dsm($emw_sm->getPropertyInfo());
			$has_sm_image_src = FALSE;
			if(!empty($emw_sm->field_support_type->value()) && $uri = $emw_sm->field_support_type->field_image->value()['uri']){
				$sm_image_src = file_create_url($uri);
				$has_sm_image_src = TRUE;
			} else {
				$sm_image_src = 'http://placehold.it/200x200';
			}
			$description_markup .= '	<li>';
			/*$description_markup .= '		<div class="sm-icon-container">';
			$description_markup .= '			<img src="'.$sm_image_src.'">';
			$description_markup .= '		</div>';*/
			$description_markup .= '		'.$sm_title;
			$description_markup .= '	</li>';
		}
		$description_markup .= '	</ol>';
		$description_markup .= '</div>';

		// ************************************************
		// 		Were ready so lets build the form
		// ************************************************
		$form = array();

		$form['meta-information'] = array(
			'#type' => 'fieldset',
			'#attributes' => array('class' => array('meta-information')),
		);
		$form['meta-information']['header'] = array(
			'#markup' => 'Add <strong>'.$book_title.'</strong> and <strong>('.$sm_count.')</strong> support material'.$is_plural_text.' to My Favorites.',
			'#prefix' => '<p>',
			'#suffix' => '</p>',
		);
		$form['meta-information']['description'] = array(
			//'#markup' => $node_to_add->field_description['und'][0]['safe_value'],
			'#markup' => $description_markup,
			'#prefix' => '<p>',
			'#suffix' => '</p>',
		);

		$form['favorite-folder-container'] = array(
			'#type' => 'fieldset',
			'#attributes' => array('class' => array('favorite-folder-container')),
		);
		$form['favorite-folder-container']['svg-style'] = array (
			'#markup' => '<svg class="svg" xmlns="http://www.w3.org/2000/svg" width="261.406" height="31" viewBox="0 0 261.406 31">
                <path d="M469,1208h58.953c64.047,0,60.953,30,72,30s8.047-30,71.012-30H729v-1H469v1Z" transform="translate(-468.906 -1207)"></path>
              </svg>',
		);
		$form['favorite-folder-container']['favorites_folder'] = array(
			'#type' => 'select',
			'#title' => t('Add to Favorite List'),
			'#options' => $favorite_folder_ids,
		);

		$form['favorite-folder-container']['new_folder_name'] = array(
			'#type' => 'textfield',
			'#attributes' => array(
				'class' => array('form-control'),
				'placeholder' => t('Name of list...'),
			),
			'#size' => 60,
			'#maxlength' => 128,
			'#states' => array(
				// Hide the settings when the cancel notify checkbox is disabled.
				'visible' => array(
					':input[name="favorites_folder"]' => array('value' => '0'),
				),
			),
			//'#required' => FALSE,
			//'#theme_wrappers' => array(),
		);

		$form['favorite-folder-container']['book_to_favorite'] = array('#type' => 'hidden', '#value' => $book_id);
		$form['favorite-folder-container']['nodes_to_favorite'] = array('#type' => 'hidden', '#value' => $nids);

		$form['actions'] = array(
			'#type' => 'fieldset',
			'#attributes' => array('class' => array('modal-actions')),
		);

		$form['actions']['submit'] = array(
			'#type' => 'submit',
			'#value' => t('Add Material'),
			'#attributes' => array(
				'class' => array('btn btn-blue btn-add-material-all'),
			),
		);

		return $form;
	}

	function my_favorites_rename_folder_cancel(&$form, &$form_state) {
		$form_state['ajax_commands'][] = ctools_modal_command_dismiss();
	}

	function my_favorites_add_all_favorite_form_validate(&$form, &$form_state) {
		$selected_folder_nid = $form_state['values']['favorites_folder'];

		if($selected_folder_nid == 0) { //Create New Folder Option was selected
			//So check if there is text in the create new folder option
			$new_folder_name = $form_state['values']['new_folder_name'];
			if(empty($new_folder_name)) {
				form_set_error('favorite-folder-container[new_folder_name]', 'Please specify a name for your new folder');
			}
		}
	}

	function my_favorites_add_all_favorite_form_submit(&$form, &$form_state) {
		$book_to_favorite_nid = $form_state['values']['book_to_favorite'];
		$nodes_to_favorite_nids_raw = $form_state['values']['nodes_to_favorite'];
		$selected_folder_nid = $form_state['values']['favorites_folder'];

		if($selected_folder_nid == 0) { //Create New Folder Option was selected
			// Create New Folder Content Entity
			$new_folder_name = $form_state['values']['new_folder_name'];
			$selected_folder_nid = _create_new_folder_from_modal_node($new_folder_name);
		}
		$emw_selected_folder = entity_metadata_wrapper('node', $selected_folder_nid);

		//Setup Array of resources to add that are not already in the favorites folder
		$resources_to_add_nids = explode('_', $book_to_favorite_nid.'_'.$nodes_to_favorite_nids_raw);

		$favorited_folder_item_nids = array();
		$favorited_folder_item_nodes = $emw_selected_folder->field_favorite_resources->value();
		foreach($favorited_folder_item_nodes as $item) {
			$favorited_folder_item_nids[] = $item->nid;
		}

		$resources_to_add_nids = array_diff($resources_to_add_nids, $favorited_folder_item_nids);

		global $user;
		$book_node = node_load($book_to_favorite_nid);
		$form_state['ajax_commands'][] = ajax_command_invoke(NULL, "addAll", array($user->uid, $book_to_favorite_nid, $book_node->title, $book_node->field_isbn['und'][0]['safe_value']));
		foreach($resources_to_add_nids as $pos => $resource_nid){
			$emw_selected_folder->field_favorite_resources[] = $resource_nid;

			// Add the ajax command for firing the add all resources
			$resource_node = node_load($resource_nid);
			$form_state['ajax_commands'][] = ajax_command_invoke(NULL, "addFavorite", array($user->uid, $resource_nid, $resource_node->title,$resource_node->type, $book_to_favorite_nid, $book_node->title));
		}
		$emw_selected_folder->save();

		// Tell the browser to close the modal.
		$form_state['ajax_commands'][] = ctools_modal_command_dismiss();

		// Tell the browser to replace My Favorites Button Text as added
		$new_add_all_button_html = '<span class="button-text"><i class="fa fa-heart pull-right"></i>Added All</span>';
		$new_button_html = '<span class="button-text"><i class="fa fa-heart"></i>Added</span>';
		$form_state['ajax_commands'][] = ajax_command_replace('.add-all-button .button-text', $new_add_all_button_html);
		$form_state['ajax_commands'][] = ajax_command_replace('.add-button .button-text', $new_button_html);
	}

	function _create_new_folder_from_modal_node($tile_of_node) {
		global $user;

		// entity_create replaces the procedural steps in the first example of
		// creating a new object $node and setting its 'type' and uid property
		$values = array(
			'type' => 'favoritesfolder',
			'uid' => $user->uid,
			'status' => 1,
			'comment' => 0,
			'promote' => 0,
		);
		$entity = entity_create('node', $values);
		// The entity is now created, but we have not yet simplified use of it.
		// Now create an entity_metadata_wrapper around the new node entity
		// to make getting and setting values easier
		$emw_node = entity_metadata_wrapper('node', $entity);

		// Using the wrapper, we do not have to worry about telling Drupal
		// what language we are using. The Entity API handles that for us.
		$emw_node->title->set($tile_of_node);

		$emw_node->save(); // Now just save the wrapper and the entity

		return $emw_node->getIdentifier();
	}
