import module namespace jx = "http://zorba.io/modules/json-xml";

let $xml := <li>list item</li>
let $options := { "json-format" : "JsonML-object" }
return jx:xml-to-json( $xml, $options )

(: vim:set et sw=2 ts=2: :)
