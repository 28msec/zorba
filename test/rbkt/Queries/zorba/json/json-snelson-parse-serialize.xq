import module namespace json="http://www.zorba-xquery.com/modules/converters/json";

declare variable $json-element := 
<json xmlns="http://john.snelson.org.uk/parsing-json-into-xquery" type="object">
  <pair name="html" type="string">&lt;b&gt;bold&lt;/b&gt;</pair>
</json>;

json:parse(json:serialize($json-element))
