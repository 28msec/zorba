import module namespace json = "http://www.zorba-xquery.com/modules/converters/json#2";

let $json :=
  <json type="array">
    <item type="boolean">true</item>
  </json>
return json:serialize( $json )
(: vim:set et sw=2 ts=2: :)
