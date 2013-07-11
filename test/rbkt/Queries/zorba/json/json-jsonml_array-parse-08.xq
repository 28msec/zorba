import module namespace jx =
  "http://zorba.io/modules/json-xml";

let $options := { "json-format" : "JsonML-array" }
let $json := '[ { "x" : "x" } ]'
return jx:json-to-xml( $json, $options )

(: vim:set et sw=2 ts=2: :)
