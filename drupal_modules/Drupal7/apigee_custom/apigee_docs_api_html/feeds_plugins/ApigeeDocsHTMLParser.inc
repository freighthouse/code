<?php

/**
 * @file Home of the ApigeeDocsHTMLParser. Overrides the default 
 * FeedsXPathParserHTML, providing the file_path as a source.
 */
class ApigeeDocsHTMLParser extends FeedsXPathParserHTML
{
    /**
   * Implements FeedsParser::parse().
   */
    public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) 
    {
        $parser_result = parent::parse($source, $fetcher_result);

        // Add file_path.
        $file_path = $fetcher_result->getFilePath();
        foreach ($parser_result->items as &$item) {
            $item['file_path'] = $file_path;
        }
        return $parser_result;
    }

    /**
  * Override parent::getMappingSources().
  */
    public function getMappingSources() 
    {
        $mappings = parent::getMappingSources();

        $mappings['file_path'] = array(
        'name' => t('File path'),
        'description' => t('The path to the file.'),
        );

        return $mappings;
    }
}
