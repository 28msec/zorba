import module namespace json="http://www.zorba-xquery.com/modules/converters/json";

declare variable $json-value := '{ "key" : "value" }';

json:serialize( json:parse( $json-value ) )

(: vim:se et sw=2 ts=2: :)
