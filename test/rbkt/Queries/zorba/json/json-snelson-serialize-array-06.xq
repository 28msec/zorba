import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

let $json :=
  <json type="array">
    <foo type="boolean">true</foo>
  </json>
return json:serialize( $json )

(: vim:set et sw=2 ts=2: :)
