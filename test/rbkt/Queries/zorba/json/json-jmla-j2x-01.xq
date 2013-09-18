(: Simple JsonML :)

import module namespace jx = "http://zorba.io/modules/json-xml";

let $json := [ "li", "list item" ]
let $options := { "json-format" : "JsonML-array" }
return jx:json-to-xml( $json, $options )

(: vim:set et sw=2 ts=2: :)
