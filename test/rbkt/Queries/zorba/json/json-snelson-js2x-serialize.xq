import module namespace jx = "http://zorba.io/modules/json-xml";

let $json-element := 
  <json type="object">
    <pair name="html" type="string">&lt;b&gt;bold&lt;/b&gt;</pair>
  </json>
return jx:json-string-to-xml( jx:xml-to-json-string( $json-element ) )

(: vim:se et sw=2 ts=2: :)
