import module namespace jx = "http://zorba.io/modules/json-xml";

let $xml :=
  <person created="2006-11-11T19:23" modified="2006-12-31T23:59">
    <firstName>Robert</firstName>
    <lastName>Smith</lastName>
    <address type="home">
      <street>12345 Sixth Ave</street>
      <city>Anytown</city>
      <state>CA</state>
      <postalCode>98765-4321</postalCode>
    </address>
  </person>
let $options := { "json-format" : "JsonML-object" }
return jx:xml-to-json( $xml, $options )

(: vim:set et sw=2 ts=2: :)
