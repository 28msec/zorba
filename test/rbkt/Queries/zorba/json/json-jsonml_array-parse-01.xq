import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

let $json := '[ "li", "list item" ]'
let $options :=
  <options xmlns="http://www.zorba-xquery.com/modules/converters/json-options">
    <json-format value="JsonML-array"/>
  </options>
return json:parse( $json, $options )
(: vim:set et sw=2 ts=2: :)
