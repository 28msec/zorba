import module namespace uri = "http://zorba.io/modules/uri";

let $xml-uri-test := fn:doc("uri-source.xml")//uri-element

for $uri in $xml-uri-test
let $parsed-uri := uri:parse($uri)
return concat(uri:serialize($parsed-uri), "
")

