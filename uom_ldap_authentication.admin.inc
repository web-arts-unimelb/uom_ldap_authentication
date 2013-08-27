<?php
/**
 * @file
 */

function uom_ldap_authentication_settings_form() {
  $form = array('#tree' => FALSE);

  $form['basic'] = array(
    '#title' => t('Basic settings'),
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
  );

  $form['basic']['uom_ldap_authentication_departments'] = array(
    '#title' => t('Departments'),
    '#description' => t('Enter department names and numbers whose members should be allowed to log in to this Drupal. Enter one department per line in <code>number|name</code> format; e.g: <code>100|Arts</code>. Enter one department number and name per line. Department name capitalisation is ignored. Use <code>0</code> as the number if you only know the department name, e.g: <code>0|Biology</code> Leave the name empty if you only know the number, e.g: <code>211|</code>'),
    '#type' => 'textarea',
    '#rows' => 5,
    '#default_value' => variable_get('uom_ldap_authentication_departments', ''),
  );

  $form['basic']['uom_ldap_authentication_policy'] = array(
    '#title' => t('Policy'),
    '#description' => t('Set a default policy for LDAP users that do not match listed departments. This does not apply to users without LDAP entries.'),
    '#type' => 'radios',
    '#options' => array(
      0 => t('Enabled, only allow users from listed departments, reject others.'),
      1 => t('Disabled, allow users from any department.'),
    ),
    '#default_value' => variable_get('uom_ldap_authentication_policy', 1),
    '#required' => TRUE,
  );

  $form['attributes'] = array(
    '#title' => t('Attribute settings'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['attributes']['uom_ldap_authentication_numbers'] = array(
    '#title' => t('Department numbers attribute'),
    '#type' => 'textfield',
    '#description' => t('The LDAP attribute that stores department numbers.'),
    '#default_value' => variable_get('uom_ldap_authentication_numbers', 'uomdepartmentnumbers'),
    '#required' => TRUE,
  );

  $form['attributes']['uom_ldap_authentication_names'] = array(
    '#title' => t('Department names attribute'),
    '#description' => t('The LDAP attribute that stores department names.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('uom_ldap_authentication_names', 'uomdepartments'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
