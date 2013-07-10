import module namespace json = "http://zorba.io/modules/json-xml";

let $json :=
  <json type="array">
    <item type="boolean">foo</item>
  </json>
return json:serialize( $json )

(: vim:set et sw=2 ts=2: :)
