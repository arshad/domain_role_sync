<?php

/**
 * @file
 * Admin settings for domain role sync module.
 */

/**
 * Menu callback; domain role sync settings form.
 */
function domain_role_sync_admin_settings_form($form, &$form_state) {
  $site_roles = user_roles();
  $domains = domain_role_sync_get_domain_options();
  $domain_role_sync_settings = variable_get('domain_role_sync_settings');

  $form['domain_role_sync_settings'] = array(
    '#tree' => TRUE,
  );

  foreach ($domains as $domain_id => $domain) {
    $form['domain_role_sync_settings'][$domain_id] = array(
      '#type' => 'fieldset',
      '#title' => $domain,
      '#collapsible' => TRUE,
    );
    $form['domain_role_sync_settings'][$domain_id]['roles'] = array(
      '#title' => t('When a user is assigned to/removed from the domain %domain, grant/revoke user the following roles:', array(
        '%domain' => $domain,
      )),
      '#type' => 'checkboxes',
      '#options' => $site_roles,
      '#default_value' => !empty($domain_role_sync_settings[$domain_id]['roles']) ? $domain_role_sync_settings[$domain_id]['roles'] : array(),
    );
  }

  return system_settings_form($form);
}
