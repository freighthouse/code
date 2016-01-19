<?php

//------------------------------------------------------------------------------
//  Upcoming embargos Page
//------------------------------------------------------------------------------
function mnembargo_admin_embargoes()
{
	$mn_now = time();

	$headers = array(
		array('data' => t('Title'), 'field' => 'title', 'sort' => 'asc'),
		array('data' => t('Type'), 'type' => 'title', 'sort' => 'asc'),
		array('data' => t('Embargo Time'), 'field' => 'pub_time',
			'sort' => 'asc'),
	);
	$limit = 50;

	$sql = "SELECT n.title, n.type, " .
			"(n.created + m.time_to_pub) as pub_time FROM {mnembargo} m " .
			"LEFT JOIN {node} n ON n.nid = m.nid";
	$sql .= tablesort_sql($headers);
	$q = pager_query($sql, $limit);

	$types = node_get_types();
	$data = array();
	while($row = db_fetch_array($q)) {
		$row_class = "";
		if($row['pub_time'] + (60*5) < $mn_now)
			$row_class = "mnemb_red";
		else if($row['pub_time'] - (60*5) < $mn_now)
			$row_class = "mnemb_yellow";

		$data[] = array(
			'data' => array(
				$row['title'],
				$types[$row['type']]->name,
				date("r", $row['pub_time'])
			),
			'class' => $row_class
		);
	}

	if(count($data)) {
		$table = theme_table($headers, $data);
		$table .= theme('pager', NULL, $limit, 0);

		drupal_add_css(drupal_get_path('module', 'mnembargo') .
			'/css/mnembargo.css');
		drupal_add_js(drupal_get_path('module', 'mnembargo') .
			'/js/mnembargo.js');

		return $table;
	}

	return "<p>No upcoming embargoes to report.</p>";
}

//------------------------------------------------------------------------------
//  Main Admin Page and Form
//------------------------------------------------------------------------------
function mnembargo_admin_main()
{
	drupal_add_css(drupal_get_path('module', 'mnembargo') .
			'/css/mnembargo.css');

	$c .= "<div class=\"\">";
	$c .= "<div>".l("Upcoming Embargoes",
		'admin/settings/mnembargo/embargoes')."</div>";
	//if (module_exists('workflow'))
	$c .= drupal_get_form("mnembargo_config_form");
	$c .= "</div>";

	return $c;
}

function mnembargo_config_form(&$form_state) {
	$form = array();
	
	$publish_actions = array(t('Status set to Publish'));
	if (module_exists('workflow')) {
		$publish_actions[] = t('Workflow State Change');
	}
	
	$types = node_get_types();
	foreach($types as &$t){
		$form['pub_'.$t->type] = array(
			'#type' => 'fieldset',
			'#collapsible' => true,
			'#collapsed' => true,
			'#title' => t($t->name.' Publication Options'),
		);
		$form['pub_'.$t->type]['publish_action_'.$t->type] = array(
			'#type'          => 'radios',
			'#title'         => t('Publish Action'),
			'#default_value' => variable_get(
				'mnembargo_publish_action_'.$t->type, 0),
			'#options'       => $publish_actions,
			//'#description'   => t('Action to take upon publish.')
		);
		if (module_exists('workflow')) {
			$wid = workflow_get_workflow_for_type($t->type);
			$states = workflow_get_states($wid);
			
			if($wid) {
				$form['pub_'.$t->type]['workflow_cfg_state_'.$t->type] = array(
					'#type'          => 'select',
					'#title'         => t('Transition To'),
					'#default_value' => variable_get(
						'mnembargo_workflow_cfg_state_'.$t->type, ''),
					'#options'       => $states,
					'#description'   => t('State to transition to.'),
					'#prefix'        => '<div id="workflow-cfg-'.$t->type.'" '.
						'class="workflow-cfg">'
				);
				$form['pub_'.$t->type]['workflow_cfg_force_'.$t->type] = array(
					'#type'          => 'checkbox',
					'#title'         => t('Force Transition'),
					'#default_value' => variable_get(
						'mnembargo_workflow_cfg_force_'.$t->type, 0),
					'#suffix'        => '</div>'
				);
			} else {
				$form['pub_'.$t->type]['workflow_cfg_none_'.$t->type] = array(
					'#value' => '<div id="workflow-cfg-'.$t->type.'" '.
						'class="workflow-cfg">'.
						'<p class="mnembargo-noworkflow">'.
						'No workflow attached to content type '.$t->name.
						'</p></div>'
				);
			}
		}
	}
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save')
	);
	
	return $form;
}

function mnembargo_config_form_submit($form, &$form_state)
{
	$types = node_get_types();
	foreach($types as &$t){
		variable_set('mnembargo_publish_action_'.$t->type, 
			$form_state['values']['publish_action_'.$t->type]);
		if (module_exists('workflow')) {
			variable_set('mnembargo_workflow_cfg_state_'.$t->type, 
				$form_state['values']['workflow_cfg_state_'.$t->type]);
			variable_set('mnembargo_workflow_cfg_force_'.$t->type,
				$form_state['values']['workflow_cfg_force_'.$t->type]);
		}
	}
}