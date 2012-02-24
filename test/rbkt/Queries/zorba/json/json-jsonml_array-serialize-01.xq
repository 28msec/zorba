import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

let $json :=
  <li>list item</li>
let $options :=
  <options xmlns="http://www.zorba-xquery.com/modules/converters/json-options">
    <json-format value="JsonML-array"/>
  </options>
return json:serialize( $json, $options )
(: vim:set et sw=2 ts=2: :)
