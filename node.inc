<?php

/**
 * @file
 * Common mappings for the Drupal 6 node migrations.
 */

abstract class WorxNodeMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $options = array('track_changes' => 1);
    $this->highwaterField = array();

    $this->addFieldMapping('field_legacy_nid', 'nid')
         ->description('We have a common field to save the D6 nid');
  }
}

class WorxItemMigration extends WorxNodeMigration {
  public function __construct(array $arguments) {

    parent::__construct($arguments);

    //$this->addFieldMapping('D7_COLUMN_NAME', 'D6_COLUMN_NAME');
    // Map the image field to the new image field,
    // base this on the Files migration.
    //$this->addFieldMapping('D7_COLUMN_NAME', 'D6_COLUMN_NAME')
    //  ->sourceMigration('Files');
    //$this->addFieldMapping('D7_COLUMN_NAME:file_class')
    //  ->defaultValue('MigrateFileFid');
    //$this->addFieldMapping('D7_COLUMN_NAME:source_dir')
    //  ->defaultValue('http://SAME URL AS MODULE');
    //$this->addFieldMapping('D7_COLUMN_NAME:preserve_files')
    //  ->defaultValue(TRUE);
    // End image mapping.
    // This will set the text format.
    //$this->addFieldMapping('D7_COLUMN_NAME:format')
    //  ->defaultValue('filtered_html');
  }
}
