import module namespace json =
  "http://zorba.io/modules/json-xml";

let $options := { "json-format" : "JsonML-array" }
let $json := '[ { "x" : "x" } ]'
return json:parse( $json, $options )

(: vim:set et sw=2 ts=2: :)
