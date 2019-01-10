<?php
/**
 * @file
 * Migration of Press Releases.
 */

/**
 * Migration class to import Press Releases from XML Source.
 */
class SunrunPressReleasesMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed of Press Releases');
    // There isn't a consistent way to automatically identify appropriate
    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'Title' => t('Press Release Title'),
      'ReleaseText' => t('Release Body'),
      'Date' => t('Date'),
      'ReleaseID' => t('Release ID'),
    );
    // Items list
    $items_list  = variable_get('sunrun_press_release_list_url', 'http://xml.corporate-ir.net/irxmlclient.asp?compid=245283&reqtype=NEWSRELEASES_2');
    // Item URL
    $items_item  = variable_get('sunrun_press_release_item_url', 'http://xml.corporate-ir.net/irxmlclient.asp?compid=245283&reqtype=releasetxt&reqid=:id');
    // Source
    $this->source = new MigrateSourceList(new MigrateListPressReleasesXML($items_list),
      new MigrateItemXML($items_item), $fields, array('track_changes' => TRUE));
    // Destination node
    $this->destination = new MigrateDestinationNode('press_release');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'ReleaseID' => array(
          'type' => 'varchar',
          'length' => 10,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );
    // Adding fields
    $this->addFieldMapping('title', 'Title')->xpath('/IRXML/NewsReleaseText/Title');
    $this->addFieldMapping('body',  'ReleaseText')->xpath('/IRXML/NewsReleaseText/ReleaseText');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('field_source_date', 'Date')->xpath('/IRXML/NewsReleaseText/Date');
    // We get this on prepare row
    $this->addFieldMapping('field_source_id', 'ReleaseID');
  }
  /**
   * Prepare row
   */
  public function prepareRow($row) {
    // Source ID
    $row->field_source_id = $row->ReleaseID;
  }
}

/**
 * Extends the MigrateListXML in order to add custom functionality
 */
class MigrateListPressReleasesXML extends MigrateListXML {
  /**
   * Override this method to get the IDs of custom XML
   */
  protected function getIDsFromXML(SimpleXMLElement $xml) {
    $ids = array();
    foreach ($xml->NewsReleases->NewsRelease as $Release) {
      $ids[] = (string)$Release->attributes()->{'ReleaseID'};
    }
    return array_unique($ids);
  }
  /**
   * Override this method with a particular structure
   */
  public function computeCount() {
    $xml = simplexml_load_file($this->listUrl);
    // Number of sourceid elements beneath the top-level element.
    $count = count($xml->NewsReleases->NewsRelease);
    return $count;
  }  
}