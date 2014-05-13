<?php

/**
 * @file
 * Implements hook_migrate_api().
 */
function worx_migrate_migrate_api() {
  $api = array(
    'api' => 2,
    // Give the group a human-readable title.
    'groups' => array(
      'worx_migrations' => array(
        'title' => t('Worx Migration'),
      ),
    ),
  );
  return $api;
}

