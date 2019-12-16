<?php

/**
 * @file
 * The form in the admin section for remove_nodes module.
 */

/**
 * Implements hook_form().
 */
function remove_nodes_form($form, &$form_state) {
  // Get saved settings.
  $saved_settings = variable_get('remove_nodes');

  $form['#tree'] = TRUE;
  $form['#attributes']['enctype'] = 'multipart/form-data';

  $form['fieldset'] = [
    '#type' => 'fieldset',
    '#title' => t('Fieldset'),
    "#prefix" => '<div id="form-fieldset">',
    "#suffix" => '</div>',
    '#collapsible' => FALSE,
  ];

  $form['fieldset']['email'] = [
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#required' => TRUE,
    '#default_value' => isset($saved_settings['email']) ? $saved_settings['email'] : '',
    '#description' => t("Please enter email to which a confirmation email will be sent for deletion."),
    '#size' => 30,
    '#maxlength' => 30,
    '#element_validate' => ['remove_nodes_email_validate'],
  ];

  // Get list of Content types.
  $content_types_objects = node_type_get_types();
  if (!empty($content_types_objects)) {
    foreach ($content_types_objects as $content_type) {
      $form['fieldset'][$content_type->type]['hours'] = [
        '#type' => 'numberfield',
        '#title' => t('Node lifetime for "@content_type" content type', ['@content_type' => $content_type->name]),
        '#description' => t('Select how long this nodes need to save on the site (in hours). Set 0 for skip. Max 8760 hours.'),
        '#min' => 0,
        '#max' => 8760,
        '#step' => 1,
        '#default_value' => isset($saved_settings[$content_type->type]['hours']) ? $saved_settings[$content_type->type]['hours'] : 0,
      ];
    }
  }
  else {
    $form['fieldset']['#suffix'] = $form['fieldset']['#suffix'] . t('No content created yet.');
  }


  $form['fieldset']['submit'] = [
    '#type' => 'submit',
    '#value' => t('Submit'),
  ];

  return $form;
}

/**
 * Email validation function.
 */
function remove_nodes_email_validate($element) {
  if (!valid_email_address($element['#value'])) {
    form_error($element, t('Please enter a valid email address.'));
  }
}

/**
 * Submit handler for remove_nodes_form().
 */
function remove_nodes_form_submit($form, &$form_state) {
  unset($form_state['values']['fieldset']['submit']);
  variable_set('remove_nodes', $form_state['values']['fieldset']);
}
