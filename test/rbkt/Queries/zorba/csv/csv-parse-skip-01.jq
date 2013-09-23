import module namespace csv = "http://zorba.io/modules/json-csv";
import module namespace file = "http://expath.org/ns/file";

declare variable $rbktPath as xs:string external;

let $file := concat( $rbktPath, "/Queries/zorba/csv/sample_files/csv-01.csv" )
let $values := file:read-text( $file )
return subsequence( csv:parse( $values ), 2 )

(: vim:set syntax=xquery et sw=2 ts=2: :)
