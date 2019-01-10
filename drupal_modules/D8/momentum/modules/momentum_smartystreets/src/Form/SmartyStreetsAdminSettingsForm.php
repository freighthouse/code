<?php

/**
 * @file
 * Contains \Drupal\smartystreets\Form\SmartyStreetsAdminSettingsForm.
 */

namespace Drupal\smartystreets\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Url;

/**
 * Configure SmartyStreets settings for this site.
 */
class SmartyStreetsAdminSettingsForm extends ConfigFormBase {

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'smartystreets_admin_settings';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return ['smartystreets.settings'];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config('smartystreets.settings');

    $form['hostname'] = [
      '#type' => 'details',
      '#title' => 'Hostnames',
      '#description' => t('This module leverages three SmartyStreets APIs: US Street Address API, US ZIP Code API and US Autocomplete API. To learn more about each one, read the @documentation_url.<br /><br /> Enter the appropriate hostname for each API below.',
      array(
        '@documentation_url' => \Drupal::l(t('SmartyStreets documentation'),
                                Url::fromUri('https://smartystreets.com/docs',
                                array())),
      )),
      '#open' => TRUE,
    ];

    $form['hostname']['hostname_us_street_address'] = [
      '#type' => 'textfield',
      '#title' => t('US Street Address API'),
      '#required' => TRUE,
      '#default_value' => $config->get('hostname_us_street_address'),
      '#description' => t('<em>Example:</em> api.smartystreets.com'),
    ];

    $form['hostname']['hostname_us_zip_code'] = [
      '#type' => 'textfield',
      '#title' => t('US ZIP Code API'),
      '#required' => TRUE,
      '#default_value' => $config->get('hostname_us_zip_code'),
      '#description' => t('<em>Example:</em> us-zipcode.api.smartystreets.com'),
    ];

    $form['hostname']['hostname_us_autocomplete'] = [
      '#type' => 'textfield',
      '#title' => t('US Autocomplete API'),
      '#required' => TRUE,
      '#default_value' => $config->get('hostname_us_autocomplete'),
      '#description' => t('<em>Example:</em> autocomplete-api.smartystreets.com'),
    ];

    $form['keys'] = [
      '#type' => 'details',
      '#title' => 'Secret API keys',
      '#description' => t('Enter your SmartyStreets API credentials below. To generate a secret key pair, visit @authentication_url.',
      array(
        '@authentication_url' => \Drupal::l(t('SmartyStreets Authentication'),
                                 Url::fromUri('http://smartystreets.com/docs/authentication',
                                 array())),
      )),
      '#open' => TRUE,
    ];

    $form['keys']['auth_id'] = [
      '#type' => 'textfield',
      '#title' => t('SmartyStreets Auth ID'),
      '#required' => TRUE,
      '#default_value' => $config->get('auth_id'),
    ];

    $form['keys']['auth_token'] = [
      '#type' => 'textfield',
      '#title' => t('SmartyStreets Auth Token'),
      '#required' => TRUE,
      '#default_value' => $config->get('auth_token'),
    ];

    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function validateForm(array &$form, FormStateInterface $form_state) {
    parent::validateForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    $config = $this->config('smartystreets.settings');

    $config
      ->set('hostname_us_street_address', $form_state->getValue('hostname_us_street_address'))
      ->set('hostname_us_zip_code', $form_state->getValue('hostname_us_zip_code'))
      ->set('hostname_us_autocomplete', $form_state->getValue('hostname_us_autocomplete'))
      ->set('auth_id', $form_state->getValue('auth_id'))
      ->set('auth_token', $form_state->getValue('auth_token'))
      ->save();

    parent::submitForm($form, $form_state);
  }

}
