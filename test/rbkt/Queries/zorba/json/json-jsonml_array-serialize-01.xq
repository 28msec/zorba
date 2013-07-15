import module namespace jx = "http://zorba.io/modules/json-xml";

let $json :=
  <li>list item</li>
let $options := { "json-format" : "JsonML-array" }
return jx:xml-to-json-string( $json, $options )

(: vim:set et sw=2 ts=2: :)
