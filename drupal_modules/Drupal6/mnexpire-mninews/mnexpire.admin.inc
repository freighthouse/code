<?php

//------------------------------------------------------------------------------
//  Upcoming expirations Page
//------------------------------------------------------------------------------
function mnexpire_admin_expirations()
{
    $mn_now = time();

    $headers = array(
    array('data' => t('Title'), 'field' => 'title', 'sort' => 'asc'),
    array('data' => t('Type'), 'type' => 'title', 'sort' => 'asc'),
    array('data' => t('Expiration Time'), 'field' => 'exp_time',
    'sort' => 'asc'),
    );
    $limit = 50;

    $sql = "SELECT n.title, n.type, " .
    "(n.created + m.time_to_exp) as exp_time FROM {mnexpire} m " .
    "LEFT JOIN {node} n ON n.nid = m.nid";
    $sql .= tablesort_sql($headers);
    $q = pager_query($sql, $limit);

    $types = node_get_types();
    $data = array();
    while($row = db_fetch_array($q)) {
        $row_class = "";
        if($row['exp_time'] + (60*5) < $mn_now) {
            $row_class = "mnexp_red"; 
        }
        else if($row['exp_time'] - (60*5) < $mn_now) {
            $row_class = "mnexp_yellow"; 
        }

        $data[] = array(
        'data' => array(
        $row['title'],
        $types[$row['type']]->name,
        date("r", $row['exp_time'])
        ),
        'class' => $row_class
        );
    }

    if(count($data)) {
        $table = theme_table($headers, $data);
        $table .= theme('pager', null, $limit, 0);

        drupal_add_css(
            drupal_get_path('module', 'mnexpire') .
            '/css/mnexpire.css'
        );
        drupal_add_js(
            drupal_get_path('module', 'mnexpire') .
            '/js/mnexpire.js'
        );

        return $table;
    }

    return "<p>No upcoming expirations to report.</p>";
}

//------------------------------------------------------------------------------
//  Main Admin Page and Form
//------------------------------------------------------------------------------
function mnexpire_admin_main()
{
    drupal_add_css(
        drupal_get_path('module', 'mnexpire') .
        '/css/mnexpire.css'
    );

    $c .= "<div class=\"\">";
    $c .= "<div>".l(
        "Upcoming Expirations",
        'admin/settings/mnexpire/expirations'
    )."</div>";
    //if (module_exists('workflow'))
    $c .= drupal_get_form("mnexpire_config_form");
    $c .= "</div>";

    return $c;
}

function mnexpire_config_form(&$form_state) 
{
    $form = array();
    
    $expire_actions = array(t('Status set to Not Published'),t('Delete Node'));
    if (module_exists('workflow')) {
        $expire_actions[] = t('Workflow State Change');
    }
    
    $types = node_get_types();
    foreach($types as &$t){
        $form['exp_'.$t->type] = array(
        '#type' => 'fieldset',
        '#collapsible' => true,
        '#collapsed' => true,
        '#title' => t($t->name.' Expiration Options'),
        );
        $form['exp_'.$t->type]['expire_action_'.$t->type] = array(
        '#type'          => 'radios',
        '#title'         => t('Expire Action'),
        '#default_value' => variable_get(
            'mnexpire_expire_action_'.$t->type, 0
        ),
        '#options'       => $expire_actions,
        //'#description'   => t('Action to take upon expiration.')
        );
        if (module_exists('workflow')) {
            $wid = workflow_get_workflow_for_type($t->type);
            $states = workflow_get_states($wid);
            
            if($wid) {
                $form['exp_'.$t->type]['workflow_cfg_state_'.$t->type] = array(
                '#type'          => 'select',
                '#title'         => t('Transition To'),
                '#default_value' => variable_get(
                    'mnexpire_workflow_cfg_state_'.$t->type, ''
                ),
                '#options'       => $states,
                '#description'   => t('State to transition to.'),
                '#prefix'        => '<div id="workflow-cfg-'.$t->type.'" '.
                'class="workflow-cfg">'
                );
                $form['exp_'.$t->type]['workflow_cfg_force_'.$t->type] = array(
                '#type'          => 'checkbox',
                '#title'         => t('Force Transition'),
                '#default_value' => variable_get(
                    'mnexpire_workflow_cfg_force_'.$t->type, 0
                ),
                '#suffix'        => '</div>'
                );
            } else {
                $form['exp_'.$t->type]['workflow_cfg_none_'.$t->type] = array(
                '#value' => '<div id="workflow-cfg-'.$t->type.'" '.
                'class="workflow-cfg">'.
                '<p class="mnexpire-noworkflow">'.
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

function mnexpire_config_form_submit($form, &$form_state)
{
    $types = node_get_types();
    foreach($types as &$t){
        variable_set(
            'mnexpire_expire_action_'.$t->type, 
            $form_state['values']['expire_action_'.$t->type]
        );
        if (module_exists('workflow')) {
            variable_set(
                'mnexpire_workflow_cfg_state_'.$t->type, 
                $form_state['values']['workflow_cfg_state_'.$t->type]
            );
            variable_set(
                'mnexpire_workflow_cfg_force_'.$t->type,
                $form_state['values']['workflow_cfg_force_'.$t->type]
            );
        }
    }
}