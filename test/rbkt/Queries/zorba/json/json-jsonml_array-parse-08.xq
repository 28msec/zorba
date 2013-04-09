import module namespace json =
  "http://www.zorba-xquery.com/modules/converters/json";

let $opt :=
  <options xmlns="http://www.zorba-xquery.com/modules/converters/json-options">
    <json-format value="JsonML-array"/>
  </options>
let $json := '[ { "x" : "x" } ]'
return json:parse( $json, $opt )

(: vim:set et sw=2 ts=2: :)
