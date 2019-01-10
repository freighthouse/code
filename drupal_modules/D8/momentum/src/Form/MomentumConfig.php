<?php
/**
 * @file
 * Contains Drupal\momentum\Form\MomentumConfig.
 */
namespace Drupal\momentum\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

class MomentumConfig extends ConfigFormBase {
  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return [
      'momentum.settings',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'MomentumConfig';
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config('momentum.settings');

    $form['momentum_api'] = [
      '#type' => 'fieldset',
      '#title' => $this->t('Momentum API'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    ];
    $form['momentum_api']['momentum_key'] = [
      '#type' => 'textfield',
      '#title' => $this->t('API Key'),
      '#description' => $this->t('Enter your Momentum API Key here.'),
      '#default_value' => $config->get('momentum_key'),
      '#required' => TRUE,
    ];
    $form['momentum_api']['momentum_parent'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Group Name'),
      '#default_value' => $config->get('momentum_parent'),
      '#description' => $this->t('Parent organization related to your Momentum API Key.'),
    ];
    $form['momentum_api']['momentum_email'] = [
      '#type' => 'email',
      '#title' => $this->t('Email'),
      '#description' => $this->t('Enter the email address associated with your Momentum API Key.'),
      '#default_value' => $config->get('momentum_email'),
    ];
    $form['momentum_api']['momentum_url'] = [
      '#type' => 'textfield',
      '#title' => $this->t('API URL'),
      '#description' => $this->t('The Momentum API URL.  <i>**Changing this could break some functionality on your site!**</i>'),
      '#default_value' => $config->get('momentum_url'),
    ];
    $form['momentum_api']['test'] = [
      '#type' => 'button',
      '#title' => $this->t('Test API'),
      '#value' => $this->t('Test connection'),
      '#executes_submit_callback' => TRUE,
      '#submit' => ['_momentum_test'],
    ];
    $form['momentum_processing_details'] = [
      '#type' => 'fieldset',
      '#title' => $this->t('Processing Details'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    ];
    $process = [0 => t('Cron <i>(Batched)</i>'), 1 => t('Immediate')];
    $form['momentum_processing_details']['momentum_process'] = [
      '#type' => 'radios',
      '#title' => $this->t('Processing mode'),
      '#options' => $process,
      '#description' => $this->t('Mode to process letters, batches will process a defined set of letters every 5 - 10 minutes.<br /><i>"Immediate"</i> will send the letter to Momentum individually.'),
      '#default_value' => $config->get('momentum_process'),
    ];
    $form['momentum_processing_details']['momentum_debug'] = [
      '#type' => 'checkbox',
      '#title' => $this->t('Debug Results'),
      '#description' => $this->t('Display debug results.'),
      '#default_value' => $config->get('momentum_debug'),
    ];
    $form['momentum_processing_details']['momentum_batch_size'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Size of the batch to process'),
      '#description' => $this->t('Number of items to process per batch.'),
      '#default_value' => $config->get('momentum_batch_size'),
    ];

    $form['momentum_error'] = [
      '#type' => 'fieldset',
      '#title' => $this->t('Error texts'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    ];
    $form['momentum_error']['momentum_error_description'] = [
      '#type' => 'textarea',
      '#title' => $this->t('Error descriptions'),
      '#description' => $this->t('Type the error text received then | (pipe char) and the new description.'),
      '#default_value' => $config->get('momentum_error_description'),
    ];

    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    parent::submitForm($form, $form_state);

    $this->config('momentum.settings')
      ->set('momentum_key', $form_state->getValue('momentum_key'))
      ->set('momentum_parent', $form_state->getValue('momentum_parent'))
      ->set('momentum_email', $form_state->getValue('momentum_email'))
      ->set('momentum_url', $form_state->getValue('momentum_url'))
      ->set('momentum_process', $form_state->getValue('momentum_process'))
      ->set('momentum_debug', $form_state->getValue('momentum_debug'))
      ->set('momentum_batch_size', $form_state->getValue('momentum_batch_size'))
      ->set('momentum_error_description', $form_state->getValue('momentum_error_description'))
      ->save();
  }

}
