import module namespace file = "http://expath.org/ns/file";
import module namespace string = "http://www.zorba-xquery.com/modules/string";

declare variable $rbktPath as xs:string external;

let $x := file:read-text(concat($rbktPath, "/Queries/zorba/file/sample_files/sample.txt"))
return ($x, string:is-streamable($x), string:is-streamable("test"))

