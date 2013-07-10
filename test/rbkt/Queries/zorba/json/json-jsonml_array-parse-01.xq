import module namespace json = "http://zorba.io/modules/json-xml";

let $json := '[ "li", "list item" ]'
let $options :=
  <options xmlns="http://zorba.io/modules/json-xml-options">
    <json-format value="JsonML-array"/>
  </options>
return json:parse( $json, $options )

(: vim:set et sw=2 ts=2: :)
