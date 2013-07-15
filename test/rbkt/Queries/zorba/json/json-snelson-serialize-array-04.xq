import module namespace jx = "http://zorba.io/modules/json-xml";

let $json :=
  <json type="array">
    <item type="number">1</item>
  </json>
return jx:xml-to-json-string( $json )

(: vim:set et sw=2 ts=2: :)
