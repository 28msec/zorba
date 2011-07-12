import module namespace z = "http://www.zorba-xquery.com/modules/xml";

for $var in z:parse-xml-fragment("<from1>Jani</from1><from2>Jani</from2><from3>Jani</from3>", "urn:foo", "e")
return <fragment base="{fn:base-uri($var)}">{ $var }</fragment>
