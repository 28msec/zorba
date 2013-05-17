import module namespace uri = "http://www.zorba-xquery.com/modules/uri";

let $xml-uri-test := fn:doc("uri-source.xml")//uri-element/text()

for $uri in $xml-uri-test
return uri:parse($uri)
