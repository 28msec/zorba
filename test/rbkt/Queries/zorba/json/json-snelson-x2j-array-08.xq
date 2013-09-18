import module namespace jx = "http://zorba.io/modules/json-xml";

let $xml :=
  <json type="array">
    <item>false</item>
  </json>
return jx:xml-to-json( $xml )

(: vim:set et sw=2 ts=2: :)
