import module namespace jx = "http://zorba.io/modules/json-xml";

let $xml :=
  <sn:json xmlns:sn="http://john.snelson.org.uk/parsing-json-into-xquery" type="object">
    <sn:pair name="a" type="number">1</sn:pair>
  </sn:json>
return jx:xml-to-json( $xml )

(: vim:set et sw=2 ts=2: :)
