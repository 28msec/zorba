import module namespace jx = "http://zorba.io/modules/json-xml";

let $json :=
  <json type="array">
    hello
  </json>
return jx:xml-to-json( $json )

(: vim:set et sw=2 ts=2: :)
