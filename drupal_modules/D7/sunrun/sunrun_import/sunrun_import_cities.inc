<?php
/**
 * @file
 * Migration of Cities.
 */

/**
 * Migration class to import Cities nodes from external source.
 */
class SunrunCitiesMigration extends Migration {
  public function __construct($arguments) {

    parent::__construct($arguments);
    $this->description = t('Import cities from CSV file.');
    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'path' => array('type' => 'varchar',
                           'length' => 255,
                           'not null' => TRUE,
                           'description' => 'Path',
                          ),
        ),
        MigrateDestinationNode::getKeySchema()
      );
    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'sunrun_import') . '/sources/cities.csv', $this->csvcolumns(), array('header_rows' => 1));
    // Destination node type
    $this->destination = new MigrateDestinationNode('city');
    // Mapping fields
    $this->addFieldMapping('title', 'name');
    $this->addFieldMapping('body', 'body')
         ->description('See prepareRow().');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    // Featured content
    $this->addFieldMapping('field_title', 'hero_heading');
    $this->addFieldMapping('field_content', 'hero_supporting_text');
    $this->addFieldMapping('field_content:format')->defaultValue('full_html');
    // Metatags
    $this->addFieldMapping('metatag_title', 'meta_title');
    $this->addFieldMapping('metatag_description', 'meta_description');
    $this->addFieldMapping('metatag_keywords', 'meta_keywords');    
  }

  protected function csvcolumns() {
    return array(
      array('date_modified', 'Date modified'),
      array('name', 'City name'),
      array('path', 'Path'),
      array('meta_title', 'Meta title'),
      array('meta_description', 'Meta description'),
      array('meta_keywords', 'Meta keywords'),
      array('hero_heading', 'Hero heading'),
      array('hero_supporting_text', 'Hero supporting text'),
      array('top_area_headline', 'Top area headline'),
      array('top_area_supporting_text', 'Top area supporting text'),
      array('main_area_headline', 'Main area headline'),
      array('main_area_body_text', 'Main area body text'),
      array('solar_resources', 'Solar resources'),
      array('solar_incentives_copy', 'Solar incentives copy'),
    );
  }

  public function prepareRow($row) {
    $row->body = '<h1>' . $row->top_area_headline . '</h1>';
    $row->body.= $row->top_area_supporting_text;
    $row->body.= '<h1>' . $row->main_area_headline . '</h1>';
    $row->body.= $row->main_area_body_text;
    // @todo fix this on source CSV
    // $row->field_solar_resources = '';
  }
}
