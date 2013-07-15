import module namespace jx="http://zorba.io/modules/json-xml";

declare variable $json-element := 
<json xmlns="http://john.snelson.org.uk/parsing-json-into-xquery" type="object">
  <pair name="html" type="string">&lt;b&gt;bold&lt;/b&gt;</pair>
</json>;

jx:json-string-to-xml( jx:xml-to-json-string( $json-element ) )

(: vim:se et sw=2 ts=2: :)
