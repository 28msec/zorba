import module namespace jx = "http://zorba.io/modules/json-xml";

let $xml :=
  <json type="object">
    <pair name="a" type="number">1</pair>
  </json>
return jx:xml-to-json( $xml )

(: vim:set et sw=2 ts=2: :)
