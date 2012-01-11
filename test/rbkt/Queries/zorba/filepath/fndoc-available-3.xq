(: fn:doc-available() should accept absolute file URIs. :)

import module namespace file = "http://expath.org/ns/file";

declare variable $rbkt as xs:string external;

(: Use the "file" module to give us a URI. :)
let $doc :=
file:path-to-uri(fn:concat($rbkt, "/Queries/zorba/filepath/input.xml"))
return fn:doc-available($doc)
