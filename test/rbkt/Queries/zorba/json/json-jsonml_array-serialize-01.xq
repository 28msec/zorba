import module namespace json = "http://zorba.io/modules/json-xml";

let $json :=
  <li>list item</li>
let $options :=
  <options xmlns="http://zorba.io/modules/json-xml-options">
    <json-format value="JsonML-array"/>
  </options>
return json:serialize( $json, $options )

(: vim:set et sw=2 ts=2: :)
