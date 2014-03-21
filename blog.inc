<?php

/**
 * Common mappings for the Drupal 6 node migrations.
 */
abstract class BlogNodeMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $options = array('track_changes' => 1);
    $this->highwaterField = array();

    $this->addFieldMapping('field_legacy_nid', 'nid')
         ->description('We have a common field to save the D6 nid');
  }
}

class BlogItemMigration extends BlogNodeMigration {
  public function __construct(array $arguments) {

    parent::__construct($arguments);

    $this->addFieldMapping('D7_TABLE', 'D6_TABLE');
    // Map the image field to the new image field, base this on the Files migration
    $this->addFieldMapping('D7_TABLE', 'D6_TABLE')
      ->sourceMigration('Files');
    $this->addFieldMapping('D7_TABLE:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('D7_TABLE:source_dir')
      ->defaultValue('http://SAME URL AS MODULE');
    $this->addFieldMapping('D7_TABLE:preserve_files')
      ->defaultValue(TRUE);
    // End image mapping
    // This will set the text format
    $this->addFieldMapping('D7_TABLE:format')
      ->defaultValue('filtered_html');
  }
}

