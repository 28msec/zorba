import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

let $json :=
  <json type="object">
    <pair name="a" type="number">1</pair>
    <pair name="b" type="number">2</pair>
  </json>
return json:serialize( $json )
(: vim:set et sw=2 ts=2: :)
