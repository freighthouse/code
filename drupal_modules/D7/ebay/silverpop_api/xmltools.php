<?php
/**
 * Set of tools for converting between arrays and XML objects.
 * Based on: http://snipplr.com/view/3491/convert-php-array-to-xml-or-simple-xml-object-if-you-wish/
 */
class ArrayToXML
{
    /**
     * The main function for converting to an XML document.
     * Pass in a multi dimensional array and this recrusively loops through and builds up an XML document.
     *
     * @param array $data
     * @param string $rootNodeName - what you want the root node to be - Defaults to "data"
     * @param SimpleXMLElement $xml - should only be used recursively (i.e. ignore it)
     * @return string XML
     */
    public static function toXML( $data, $rootNodeName = 'data', &$xml=null ) {

        // turn off compatibility mode as simple xml throws a wobbly if you don't.
        if ( ini_get('zend.ze1_compatibility_mode') == 1 ) ini_set ( 'zend.ze1_compatibility_mode', 0 );
        // if ( is_null( $xml ) ) $xml = simplexml_load_string( "" ); // this didn't work -ESD
        if ( is_null( $xml ) ) $xml = simplexml_load_string("<?xml version='1.0' encoding='utf-8'?><$rootNodeName />");

        // loop through the data passed in.
        foreach( $data as $key => $value ) {

            // no numeric keys in our xml please!
            if ( is_numeric( $key ) ) {
                $numeric = 1;
                $key = $rootNodeName;
            }
            else {
            	$numeric = 0;
            }

            // delete any char not allowed in XML element names
            $key = preg_replace('/[^a-z0-9\-\_\.\:]/i', '', $key);

            // if there is another array found recrusively call this function
            if ( is_array( $value ) ) {
                $node = ArrayToXML::isAssoc( $value ) || $numeric ? $xml->addChild( $key ) : $xml;
                
                // special case, empty array
                if(sizeof($value) == 0) {
                  $node = $xml->addChild($key);
                }
                else {
                  // recrusive call.
                  if ( $numeric ) $key = 'anon';
                  ArrayToXML::toXml( $value, $key, $node );
                }
            } 
            else { // we've got a leaf node; add value to xml
            	
            		// for simple values with no funky characters in them, just add node
								if(preg_match('/^[0-9a-zA-Z\-_ @\.\/:\+]+$/', $value)) {
	                $xml->addChild( $key, $value );
								}
								else {
									// for anything with even the hint of funky characters, wrap it in CDATA
									$node = $xml->addChild($key);
		              $node = dom_import_simplexml($node);
									$node_owner = $node->ownerDocument;
									if($value !== '') {
			              // Special case: Don't add when value is empty string. Because in this case we would
			              //  prefer <KEY/> to <KEY></KEY>
										$node->appendChild($node_owner->createCDATASection($value));
									}
								}
            }
        }

        // pass back as XML
        return $xml->asXML();

    // if you want the XML to be formatted, use the below instead to return the XML
        //$doc = new DOMDocument('1.0');
        //$doc->preserveWhiteSpace = false;
        //$doc->loadXML( $xml->asXML() );
        //$doc->formatOutput = true;
        //return $doc->saveXML();
    }


    /**
     * Convert an XML document to a multi dimensional array
     * Pass in an XML document (or SimpleXMLElement object) and this recrusively loops through and builds a representative array
     *
     * @param string $xml - XML document - can optionally be a SimpleXMLElement object
     * @return array ARRAY
     */
    public static function toArray( $xml ) {
        if ( is_string( $xml ) ) $xml = new SimpleXMLElement( $xml );
        $children = $xml->children();
        if ( !$children ) return (string) $xml;
        $arr = array();
        foreach ( $children as $key => $node ) {
            $node = ArrayToXML::toArray( $node );

            // support for 'anon' non-associative arrays
            if ( $key == 'anon' ) $key = count( $arr );

            // if the node is already set, put it into an array
            if ( isset( $arr[$key] ) ) {
                if ( !is_array( $arr[$key] ) || $arr[$key][0] == null ) $arr[$key] = array( $arr[$key] );
                $arr[$key][] = $node;
            } else {
                $arr[$key] = $node;
            }
        }
        return $arr;
    }

    // determine if a variable is an associative array
    public static function isAssoc( $array ) {
        return (is_array($array) && 0 !== count(array_diff_key($array, array_keys(array_keys($array)))));
    }
}