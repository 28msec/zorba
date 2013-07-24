import module namespace jx="http://zorba.io/modules/json-xml";

let $json := '{ "key" : "value" }'
return jx:xml-to-json-string( jx:json-string-to-xml( $json ) )

(: vim:se et sw=2 ts=2: :)
