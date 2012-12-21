import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

let $json :=
  <file dir="/tmp" name="foo" size="1234" modified="2006-12-31T23:59"/>
let $options :=
  <options xmlns="http://www.zorba-xquery.com/modules/converters/json-options">
    <json-format value="JsonML-array"/>
  </options>
return json:serialize( $json, $options )

(: vim:set et sw=2 ts=2: :)
