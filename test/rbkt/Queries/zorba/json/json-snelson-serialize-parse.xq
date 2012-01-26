import module namespace json="http://www.zorba-xquery.com/modules/converters/json";

declare variable $json-value := '{ "key" : "value" }';

json:serialize( json:parse( $json-value ) )
