(: fn:doc() should NOT accept absolute file paths when the static base URI :)
(: is not a file: URI (or, more precisely, it should not treat them as :)
(: absolute file paths, but instead should resolve them as relative URIs :)
(: relative to the base URI). :)

import module namespace file = "http://www.zorba-xquery.com/modules/file";
declare base-uri "test:///foo";
declare variable $rbkt as xs:string external;

(: Use the "file" module to give us platform-dependent file paths. :)
let $doc :=
file:path-to-full-path(fn:concat($rbkt, "/Queries/zorba/filepath/input.xml"))
return fn:doc($doc)