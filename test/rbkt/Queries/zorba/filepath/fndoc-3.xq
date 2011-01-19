(: fn:doc() should accept absolute file URIs. :)

import module namespace file = "http://www.zorba-xquery.com/modules/file";
declare variable $rbkt as xs:string external;

(: Use the "file" module to give us a URI. :)
let $doc :=
file:path-to-uri(fn:concat($rbkt, "/Queries/zorba/filepath/input.xml"))
return fn:doc($doc)