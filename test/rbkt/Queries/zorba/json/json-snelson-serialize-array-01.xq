import module namespace jx = "http://zorba.io/modules/json-xml";

let $json :=
  <json type="array">
    <item type="boolean">true</item>
  </json>
return jx:xml-to-json( $json )

(: vim:set et sw=2 ts=2: :)
