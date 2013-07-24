import module namespace jx = "http://zorba.io/modules/json-xml";

let $json := [ { "key1" : "value1" }, { "key2" : "value2" } ]
return jx:json-to-xml( $json )

(: vim:set et sw=2 ts=2: :)
