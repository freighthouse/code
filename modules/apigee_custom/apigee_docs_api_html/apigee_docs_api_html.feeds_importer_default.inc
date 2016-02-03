<?php
/**
 * @file
 * Default definition of Feeds importer 'api_html'.
 */


/**
 * Implements hook_feeds_importer_default().
 */
function apigee_docs_api_html_feeds_importer_default() 
{
    $export = array();

    $feeds_importer = new stdClass();
    $feeds_importer->disabled = false; /* Edit this to true to make a default feeds_importer disabled initially */
    $feeds_importer->api_version = 1;
    $feeds_importer->id = 'api_html';
    $feeds_importer->config = array(
    'name' => 'API HTML',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'ApigeeDocsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'html',
        'direct' => 1,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'ApigeeDocsHTMLParser',
      'config' => array(
        'sources' => array(
          'xpathparser:1' => '//h1[1]',
          'xpathparser:2' => '//div[@class="container"]/div[@class="content"]/div[@class="row"]/div[@class="span12"]/child::node()',
        ),
        'rawXML' => array(
          'xpathparser:2' => 'xpathparser:2',
          'xpathparser:1' => 0,
        ),
        'context' => '.',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'api_reference',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:1',
            'target' => 'title',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'xpathparser:2',
            'target' => 'body',
            'unique' => false,
          ),
          2 => array(
            'source' => 'file_path',
            'target' => 'guid',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'Blank source 1',
            'target' => 'path_alias',
            'unique' => false,
          ),
          4 => array(
            'source' => 'xpathparser:3',
            'target' => 'menu:menu_name',
            'unique' => false,
          ),
          5 => array(
            'source' => 'Blank source 3',
            'target' => 'menu:link_title',
            'unique' => false,
          ),
          6 => array(
            'source' => 'xpathparser:4',
            'target' => 'menu:plid',
            'unique' => false,
          ),
          7 => array(
            'source' => 'Blank source 4',
            'target' => 'menu:enabled',
            'unique' => false,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
    );

    $export[$feeds_importer->id] = $feeds_importer;

    return $export;
}
