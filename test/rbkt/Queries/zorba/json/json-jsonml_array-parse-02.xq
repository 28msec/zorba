import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

let $json := '
  [ "ul",
    [ "li", "list item 1" ],
    [ "li", "list item 2" ]
  ]
'
let $options :=
  <options xmlns="http://www.zorba-xquery.com/modules/converters/json-options">
    <json-format value="JsonML-array"/>
  </options>
return json:parse( $json, $options )

(: vim:set et sw=2 ts=2: :)
