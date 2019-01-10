<?php
	function my_favorites_add_callback($js = NULL, $nid = NULL, $book_nid_to_add = NULL) {
		if ($nid == NULL) {
			return 'NO node id was sent. Error';
		}

		$node_to_add = node_load($nid);

		// Checking JavaScript is enabled.
		if (!$js) {
			//drupal_exit();
			//return;
			// If JavaScript is disabled — outputting content without the popup.
			$alias = drupal_get_path_alias($nid);
			drupal_goto("node/".$alias);
			//return drupal_get_form('my_favorites_add_favorite_form', $node_to_add);
		}
		ctools_include('ajax');
		ctools_include('modal');

		$form_state = array(
			'ajax' => TRUE,
			'title' => t($node_to_add->title),
		);

		// Use ctools to generate ajax instructions for the browser to create
		// a form in a modal popup.
		// Use [ctools_modal_command_display(t('My first popup'), $popup_content);] If it is just content with no form
		$form_state['build_info']['args'] = array($node_to_add, $book_nid_to_add);
		$output = ctools_modal_form_wrapper('my_favorites_add_favorite_form', $form_state);

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
	function my_favorites_add_favorite_form($form, $form_state, $node_to_add, $book_nid_to_add) {

		$favorite_folder_ids = [];

		//$favorite_folders = views_get_view_result('my_favorite_folders','my_favorite_folders');
		$type = 'favoritesfolder';

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

		$form = array();

		$form['#tree'] = TRUE;

		$form['meta-information'] = array(
			'#type' => 'fieldset',
			'#attributes' => array('class' => array('meta-information')),
		);
		$form['meta-information']['description'] = array(
			'#markup' => $node_to_add->field_description['und'][0]['safe_value'],
			'#prefix' => '<p>',
			'#suffix' => '</p>',
		);

		$form['favorite-folder-container'] = array(
			'#type' => 'fieldset',
			'#attributes' => array('class' => array('favorite-folder-container grady-was-here')),
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
					':input[name="favorite-folder-container[favorites_folder]"]' => array('value' => '0'),
				),
			),
			//'#required' => FALSE,
			//'#theme_wrappers' => array(),
		);

		$form['favorite-folder-container']['node_to_favorite'] = array('#type' => 'hidden', '#value' => $node_to_add);
		$form['favorite-folder-container']['book_nid_to_add'] = array('#type' => 'hidden', '#value' => $book_nid_to_add);

		$form['actions'] = array(
			'#type' => 'fieldset',
			'#attributes' => array('class' => array('modal-actions')),
		);

		$form['actions']['submit'] = array(
			'#type' => 'submit',
			'#value' => t('Add Material'),
		);

		return $form;
	}

	function my_favorites_add_favorite_form_validate(&$form, &$form_state) {
		$node_to_favorite = $form_state['values']['favorite-folder-container']['node_to_favorite'];
		$node_id_to_favorite = $node_to_favorite->nid;
		$parent_nid = $form_state['values']['favorite-folder-container']['favorites_folder'];

		if($parent_nid == 0) { //Create New Folder Option was selected
			//So check if there is text in the create new folder option
			$new_folder_name = $form_state['values']['favorite-folder-container']['new_folder_name'];
			if(empty($new_folder_name)) {
				form_set_error('favorite-folder-container[new_folder_name]', 'Please specify a name for your new folder');
			}
		} else {
			$parent_node = node_load($parent_nid);

			//Check if the node_to_favorite already exists in that folder
			$node_id_to_add_exists = false;
			$favorites_to_search = $parent_node->field_favorite_resources['und'];
			foreach ($favorites_to_search as $index => $favorite) {
				if ($favorite['target_id'] == $node_id_to_favorite) {
					$node_id_to_add_exists = true;
					break;
				}
			}
			// Return a form error if it does exist
			if ($node_id_to_add_exists) {
				form_set_error('favorite-folder-container[favorites_folder]', 'This item has already been added to this folder. Please select a different folder');
			}
		}
	}

	function my_favorites_add_favorite_form_submit(&$form, &$form_state) {
		// Setup variables for the function
		$node_to_favorite = $form_state['values']['favorite-folder-container']['node_to_favorite'];
		$node_id_to_favorite = $node_to_favorite->nid;
		$parent_nid = $form_state['values']['favorite-folder-container']['favorites_folder'];

		if($parent_nid == 0) { //Create New Folder Option was selected
			// Create New Folder Content Entity
			$new_folder_name = $form_state['values']['favorite-folder-container']['new_folder_name'];
			$parent_nid = _create_new_folder_from_modal_node($new_folder_name);
			// Set Parent Node to that content entity
			// Continue as if a regular option was selected
		}

		$parent_node = node_load($parent_nid);
		$node_to_load = node_load($node_id_to_favorite);
		$book_nid = 0;
		$book_node['title'] = 'unknown';

		if($node_to_load->type == 'support_material') { //If $node_to_favorite_type == support material
			// Then we also add the book resource above it
			/*$book_nid = $form_state['values']['favorite-folder-container']['book_nid_to_add'];
			if($book_nid == null) {
				// $form_state['values']['favorite-folder-container']['node_to_favorite']->field_related_books['und']
			}*/
			$isbn_count = count($form_state['values']['favorite-folder-container']['node_to_favorite']->field_related_books['und']);
			$book_nid = null;
			if($isbn_count == 1) {
				$book_nid = $form_state['values']['favorite-folder-container']['node_to_favorite']->field_related_books['und'][0]['target_id'];
			}
			if($book_nid != null) {
				// This is here to support some legacy situations
				$book_node = node_load($book_nid);

				// Check if any book associated with this resource is already in the favorite list
				$book_id_exists = false;
				$favorites_to_search = $parent_node->field_favorite_resources['und'];
				foreach ($favorites_to_search as $index => $favorite) {
					if ($favorite['target_id'] == $book_nid) {
						$book_id_exists = true;
					}
				}

				// if the book isn't favorited yet... Add it.
				if (!$book_id_exists) {
					$parent_node->field_favorite_resources['und'][] = array('target_id' => $book_nid);
				}
			}
		}

		//Set the target id as an element in the node entity field
		$parent_node->field_favorite_resources['und'][] = array('target_id' => $node_id_to_favorite);

		//Save the parent node to record our changes
		node_save($parent_node);

		// Tell the browser to close the modal.
		$form_state['ajax_commands'][] = ctools_modal_command_dismiss();
		global $user;
		$form_state['ajax_commands'][] = ajax_command_invoke(NULL, "addFavorite", array($user->uid, $node_id_to_favorite, $node_to_load->title,$node_to_load->type, $book_nid, $book_node->title));

		// Tell the browser to replace My Favorites Button Text as added
		$new_button_html = '<span class="button-text"><i class="fa fa-heart"></i>Added</span>';
		$form_state['ajax_commands'][] = ajax_command_replace('.add-button-for-' . $node_to_favorite->nid . ' .button-text', $new_button_html);
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
