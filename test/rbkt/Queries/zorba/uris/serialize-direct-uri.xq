import module namespace uri = "http://www.zorba-xquery.com/modules/uri";

let $xml-uri-test := fn:doc("uri-source2.xml")

for $uri in $xml-uri-test//*:uri
return ( uri:serialize($uri), "
")

