import module namespace jx="http://zorba.io/modules/json-xml";

declare variable $json-value := '{ "key" : "value" }';

jx:xml-to-json-string( jx:json-string-to-xml( $json-value ) )

(: vim:se et sw=2 ts=2: :)
