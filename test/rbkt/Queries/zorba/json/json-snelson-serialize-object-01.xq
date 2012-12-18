import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

let $json :=
  <json type="object">
    <pair name="a" type="number">1</pair>
  </json>
return json:serialize( $json )

(: vim:set et sw=2 ts=2: :)
