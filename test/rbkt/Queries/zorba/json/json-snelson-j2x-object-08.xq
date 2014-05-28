import module namespace jx = "http://zorba.io/modules/json-xml";

let $json := { "a" : 1 }
let $options := { "prefix" : "sn" }
return jx:json-to-xml( $json, $options )

(: vim:set et sw=2 ts=2: :)
