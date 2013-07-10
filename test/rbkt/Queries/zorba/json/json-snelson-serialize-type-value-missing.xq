import module namespace json = "http://zorba.io/modules/json-xml";

let $json := 
<json xmlns="http://john.snelson.org.uk/parsing-json-into-xquery" type="object">
  <pair name="a">a</pair>
</json>
return json:serialize( $json )

(: vim:set et sw=2 ts=2: :)
