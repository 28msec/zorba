import module namespace jx = "http://zorba.io/modules/json-xml";

let $json := 
<json xmlns="http://john.snelson.org.uk/parsing-json-into-xquery" type="object">
  <pair name="a" type="nothing">a</pair>
</json>
return jx:xml-to-json( $json )

(: vim:set et sw=2 ts=2: :)
