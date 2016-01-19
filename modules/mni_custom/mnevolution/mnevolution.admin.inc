<?php

//------------------------------------------------------------------------------
//  Upcoming Evolutions Page
//------------------------------------------------------------------------------
function mnevolution_admin_evolutions()
{
	$mn_now = time();

	$headers = array(
		array('data' => t('Title'), 'field' => 'title', 'sort' => 'asc'),
		array('data' => t('Type'), 'type' => 'title', 'sort' => 'asc'),
		array('data' => t('New Type'), 'field' => 'end_type', 'sort' => 'asc'),
		array('data' => t('Evolution Time'), 'field' => 'evo_time',
			'sort' => 'asc'),
	);
	$limit = 50;

	$sql = "SELECT n.title, n.type, m.end_type, " .
			"(n.created + m.time_to_evo) as evo_time FROM {mnevolution} m " .
			"LEFT JOIN {node} n ON n.nid = m.nid";
	$sql .= tablesort_sql($headers);
	$q = pager_query($sql, $limit);

	$types = node_get_types();
	$data = array();
	while($row = db_fetch_array($q)) {
		$row_class = "";
		if($row['evo_time'] + (60*5) < $mn_now)
			$row_class = "mnevo_red";
		else if($row['evo_time'] - (60*5) < $mn_now)
			$row_class = "mnevo_yellow";

		$data[] = array(
			'data' => array(
				$row['title'],
				$types[$row['type']]->name,
				($row['end_type'] == MNEVOLUTION_DEATHTYPE ? "Death" :
					$types[$row['end_type']]->name),
				date("r", $row['evo_time'])
			),
			'class' => $row_class
		);
	}

	if(count($data)) {
		$table = theme_table($headers, $data);
		$table .= theme('pager', NULL, $limit, 0);

		drupal_add_css(drupal_get_path('module', 'mnevolution') .
			'/css/mnevolution.css');
		drupal_add_js(drupal_get_path('module', 'mnevolution') .
			'/js/mnevolution.js');

		return $table;
	}

	return "<p>No upcoming evolutions to report.</p>";
}

//------------------------------------------------------------------------------
//  Main Admin Page and Form
//------------------------------------------------------------------------------
function mnevolution_admin_main()
{
	drupal_add_css(drupal_get_path('module', 'mnevolution') .
			'/css/mnevolution.css');

	$c = drupal_get_form('mnevolution_admin_main_form');
	$c .= "<div class=\"\">";
	$c .= "<div>".l("Upcoming Evolutions",
		'admin/settings/mnevolution/evolutions')."</div>";
	$c .= "<br/><h3>Evolution Settings by Node Type</h3><br/>";
	foreach(node_get_types() as $type) {
		$c .= "<div>".l($type->name,
			'admin/settings/mnevolution/edit/'.$type->type)."</div>";
	}
	$c .= "</div>";

	return $c;
}

function mnevolution_admin_main_form(&$form_state)
{
	$form = array();

	$form['explanation'] = array(
		'#type' => 'fieldset',
		'#collapsible' => true,
		'#collapsed' => true,
		'#title' => t('Evolution Explanation'),
	);
	$form['explanation']['content'] = array(
		'#value' => "<p>Evolution is done either through the Core Node " .
				"module API calls (Node Evolution), or via a SQL " .
				"modification of the Node's data (SQL Evolution).</p>" .
			"<p>The Node method is more clean, but results in data loss, " .
				"particularly with regards to comments, and other modules " .
				"who don't keep any data in the node object.</p>" .
			"<p>The SQL method will maintain data more readily, but may also " .
				"leave data in the database uncleaned up, which can result " .
				"in errors if modules are not built to handle this.</p>" .

			"<label>Node Evolution Process</label><ul>"
				."<li>Load \$old_node</li>"
				."<li>Generate \$orig_new_node</li>"
				."<li>Build \$fin_new_node</li>"
				."<li>Run Evolution Code</li>"
				."<li>Delete \$old_node</li>"
				."<li>Save \$fin_new_node</li>"
				."</ul>".

			"<label>SQL Evolution Process</label><ul>"
				."<li>Update type in Node table</li>"
				."<li>Load \$new_node</li>"
				."<li>Run Evolution Code</li>"
				."<li>Save \$new_node</li>"
				."</ul>"
	);

	$form['global_settings'] = array(
		'#type' => 'fieldset',
		'#collapsible' => true,
		'#collapsed' => true,
		'#title' => t('Global Evolution Settings'),
	);
	$form['global_settings']['mnevolution_global_evotype'] = array(
		'#type' => 'radios',
		'#title' => t('Default Evolution Type'),
		'#options' => array(t('Node Evolution'), t('SQL Evolution')),
		'#default_value' => variable_get('mnevolution_global_evotype', 0),
		'#description' => "Method for evolving nodes when no method " .
				"is specified."
	);
	$form['global_settings']['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save')
	);

	return $form;
}

function mnevolution_admin_main_form_submit($form, &$form_state)
{
	variable_set('mnevolution_global_evotype',
		$form_state['values']['mnevolution_global_evotype']);
}

//------------------------------------------------------------------------------
//  Admin Forms for Editing Type Evolutions
//------------------------------------------------------------------------------
function mnevolution_admin_type_edit($type)
{
	return drupal_get_form('mnevolution_admin_type_edit_form', $type);
}

function mnevolution_admin_type_edit_form(&$form_state, $type)
{
	$form = array();

	$form['node available_variables'] = array(
		'#value' => "<label>Node Evolution Available Variables</label><ul>"
				."<li>".t("\$old_node - Old node object, about to " .
						"be deleted.")."</li>"
				."<li>".t("\$orig_new_node - New node object in it's " .
						"original, generated form. This is the node's " .
						"current state in the database.")."</li>"
				."<li>".t("\$fin_new_node - New node object to be saved " .
						"at the end.")."</li>"
				."</ul>"
	);
	$form['sql available_variables'] = array(
		'#value' => "<label>Node Evolution Available Variables</label><ul>"
				."<li>".t("\$new_node - New node object being loaded after " .
						"the SQL modification has been done. After your " .
						"code is run, it will be saved again.")."</li>"
				."</ul>"
	);
	$form['curr_type'] = array('#type' => 'value', '#value' => $type->type);

	$db_data = _mnevolution_admin_scripts_array($type->type);
	$all_types = node_get_types();
	foreach($all_types as $t){
		if($t->type != $type->type) {
			$fs_name = $type->type."_to_".$t->type;
			$form[$fs_name] = array(
				'#type' => 'fieldset',
				'#collapsible' => true,
				'#collapsed' => true,
				'#title' => t('Evolution to '.$t->name),
			);

			$form[$fs_name][$t->type."_evolution"] = array(
				'#type' => 'textarea',
				'#title' => t('Evolution Code'),
				'#default_value' => ($db_data[$t->type]['script'] ?
									$db_data[$t->type]['script'] : ""),
				'#description' => "Do not include &lt?php, ?&gt, return, " .
						"or print statements. See above for a list of " .
						"available variables."
			);
			$form[$fs_name][$t->type."_evolution_type"] = array(
				'#type' => 'radios',
				'#title' => t('Evolution Type'),
				'#options' => array(t('Use Global Default'),
					t('Node Evolution'), t('SQL Evolution')),
				'#default_value' => ($db_data[$t->type]['evo_type'] ?
									$db_data[$t->type]['evo_type'] : 0),
				'#description' => "Method for evolving nodes during this " .
						"kind of transition."
			);
		}
	}
	/*$fs_name = $type->type."_to_death";
	$form[$fs_name] = array(
		'#type' => 'fieldset',
		'#collapsible' => true,
		'#collapsed' => true,
		'#title' => t('Evolution to Death'),
	);

	$form[$fs_name]["mnevolution_death_evolution"] = array(
		'#type' => 'textarea',
		'#title' => t('Evolution Code'),
		'#default_value' => ($db_data[MNEVOLUTION_DEATHTYPE] ?
							$db_data[MNEVOLUTION_DEATHTYPE] : ""),
		'#description' => "Do not include &lt?php, ?&gt, return, " .
				"or print statements. See above for a list of " .
				"available variables."
	);*/

	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save')
	);

	return $form;
}

function _mnevolution_admin_scripts_array($start_type)
{
	$q = "SELECT * FROM {mnevolution_scripts} WHERE start_type = '%s'";
	$db_data = array();
	$results = db_query($q, $start_type);
	while($r = db_fetch_array($results))
		$db_data[$r['end_type']] = array('script' => $r['script'],
										'evo_type' => $r['evo_type']);
	return $db_data;
}

function _mnevolution_update_script_data($start_type, $end_type,
$db_data, $form_state)
{
	if($db_data[$end_type]['script'] || $db_data[$end_type]['evo_type']){
		$valS = $form_state['values'][$end_type."_evolution"];
		$valT = $form_state['values'][$end_type."_evolution_type"];
		if($valS == "" && $valT == 0) {

			// Remove from db
			$q = "DELETE FROM {mnevolution_scripts} WHERE " .
					"start_type = '%s' AND end_type ='%s'";
			db_query($q, $start_type, $end_type);
			if(!db_affected_rows()) {
				watchdog('mnevolution', "There was an error " .
					"updating evolution scripts. op:D s_type:%s " .
					"e_type:%s", array($start_type, $end_type),
					WATCHDOG_ERROR);
			}
		} else if($valS != $db_data[$type->type]['script'] ||
		$valT != $db_data[$type->type]['evo_type']) {

			// Update db
			$q = "UPDATE {mnevolution_scripts} " .
				"SET script = '%s', evo_type = %d " .
				"WHERE start_type = '%s' AND end_type = '%s'";
			db_query($q, $valS, $valT, $start_type, $end_type);
			if(!db_affected_rows()) {
				watchdog('mnevolution', "There was an error " .
					"updating evolution scripts. op:U s_type:%s " .
					"e_type:%s", array($start_type, $end_type),
					WATCHDOG_ERROR);
			}
		}
	} else if($form_state['values'][$end_type."_evolution"] != "" ||
	$form_state['values'][$end_type."_evolution_type"]){

		// Insert into db
		$q = "INSERT INTO {mnevolution_scripts} (start_type, " .
			"end_type, script, evo_type) VALUES ('%s', '%s', '%s', %d)";
		db_query($q, $start_type, $end_type,
			$form_state['values'][$end_type."_evolution"],
			$form_state['values'][$end_type."_evolution_type"]);
		if(!db_affected_rows()) {
			watchdog('mnevolution', "There was an error " .
				"updating evolution scripts. op:I s_type:%s " .
				"e_type:%s", array($start_type, $end_type),
				WATCHDOG_ERROR);
		}
	}
}

function mnevolution_admin_type_edit_form_submit($form, &$form_state)
{
	$curr_type = $form_state['values']['curr_type'];

	$db_data = _mnevolution_admin_scripts_array($curr_type);
	foreach(node_get_types() as $type) {
		if($type->type != $curr_type) {
			_mnevolution_update_script_data($curr_type, $type->type,
				$db_data, $form_state);
		}
	}
	//_mnevolution_update_script_data($curr_type, MNEVOLUTION_DEATHTYPE,
	//	$db_data, $form_state);

	drupal_set_message(t("Evolution scripts have been updated."));
}