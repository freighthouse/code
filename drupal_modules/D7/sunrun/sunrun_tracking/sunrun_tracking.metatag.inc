<?php
/**
 * @file
 * Metatag and Tracking custom integration
 */

/**
 * Implements hook_form_FORM_ID_alter
 */
function sunrun_tracking_form_page_node_form_alter(&$form, &$form_state, $form_id) {
    if(isset($form['metatags'])) {
        $form['metatags']['#title'] = 'Metatags and Tracking';
    }
}

/**
 * Implements hook_metatag_info().
 */
function sunrun_tracking_metatag_info() {

    $info['groups']['sunrun-tracking'] = array(
        'label' => t('Sunrun Tracking'),
        'description' => t("The custom Sunrun Tracking variables are used for first and last click tracking."),
        'form' => array(
            '#weight' => 20,
        ),
    );

    // Default values for each meta tag.
    $sr_defaults = array(
        'description' => '',
        'class' => 'DrupalTextMetaTag',
        'group' => 'sunrun-tracking',
        'element' => array(
            '#theme' => 'metatag_property',
        ),
    );

    $info['tags']['channel'] = array(
        'label' => t('Sunrun: Channel'),
        'description' => t("The custom channel created per node/page for tracking."),
        'class' => 'DrupalTextMetaTag',
        'weight' => 10,
    ) +  $sr_defaults;

    $info['tags']['lead_source'] = array(
        'label' => t('Sunrun: Lead Source'),
        'description' => t("The custom lead source created per node/page for tracking."),
        'class' => 'DrupalTextMetaTag',
        'weight' => 11,
    ) + $sr_defaults;

    $info['tags']['lead_type'] = array(
        'label' => t('Sunrun: Lead Type'),
        'description' => t("The custom lead type created per node/page for tracking."),
        'class' => 'DrupalTextMetaTag',
        'weight' => 11,
    ) + $sr_defaults;

    $info['tags']['campid'] = array(
            'label' => t('Sunrun: Campid'),
            'description' => t("The custom lead type created per node/page for tracking."),
            'class' => 'DrupalTextMetaTag',
            'weight' => 11,
        ) + $sr_defaults;

    $info['tags']['offer_promotion'] = array(
            'label' => t('Sunrun: Offer Promotion'),
            'class' => 'DrupalTextMetaTag',
            'weight' => 12,
        ) + $sr_defaults;


    return $info;
}
