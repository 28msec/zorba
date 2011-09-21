(: fn:doc() should accept absolute file paths. :)

import module namespace file = "http://expath.org/ns/file";

declare variable $rbkt as xs:string external;

(: Use the "file" module to give us platform-dependent file paths. :)
let $doc :=
file:resolve-path(fn:concat($rbkt, "/Queries/zorba/filepath/input.xml"))
return fn:doc($doc)
