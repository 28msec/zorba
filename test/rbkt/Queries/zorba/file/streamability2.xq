import module namespace file = "http://expath.org/ns/file";
import module namespace string = "http://zorba.io/modules/string";

declare variable $rbktPath as xs:string external;

(: test materialization of a streamable string :)
let $x := file:read-text(concat($rbktPath, "/Queries/zorba/file/sample_files/sample.txt"))
return ($x, $x)
