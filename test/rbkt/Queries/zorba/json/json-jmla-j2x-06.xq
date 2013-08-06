(: try parsing an empty value :)

import module namespace jx = "http://zorba.io/modules/json-xml";

let $json := [ ]
let $options := { "json-format" : "JsonML-array" }
return jx:json-to-xml( $json, $options )

(: vim:set et sw=2 ts=2: :)
