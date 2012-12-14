import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

let $json := 
<json xmlns="http://john.snelson.org.uk/parsing-json-into-xquery" type="object">
  <pair name="a" type="nothing">a</pair>
</json>
return json:serialize( $json )

(: vim:set et sw=2 ts=2: :)
