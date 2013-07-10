import module namespace json = "http://zorba.io/modules/json-xml";

let $json :=
  <json type="object">
    <pair name="a" type="number">1</pair>
  </json>
return json:serialize( $json )

(: vim:set et sw=2 ts=2: :)
