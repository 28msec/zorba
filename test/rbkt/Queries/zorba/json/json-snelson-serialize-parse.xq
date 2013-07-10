import module namespace json="http://zorba.io/modules/json-xml";

declare variable $json-value := '{ "key" : "value" }';

json:serialize( json:parse( $json-value ) )

(: vim:se et sw=2 ts=2: :)
