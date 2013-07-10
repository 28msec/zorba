import module namespace json = "http://zorba.io/modules/json-xml";

let $json :=
  <ul>
    <li>list item 1</li>
    <li>list item 2</li>
  </ul>
let $options := { "json-format" : "JsonML-array" }
return json:serialize( $json, $options )

(: vim:set et sw=2 ts=2: :)
