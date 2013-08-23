import module namespace csv = "http://zorba.io/modules/csv";
import module namespace file = "http://expath.org/ns/file";

declare variable $rbktPath as xs:string external;

let $file := concat( $rbktPath, "/Queries/zorba/csv/sample_files/csv-quote-escape-01.txt" )
let $values := file:read-text( $file )
let $options := { "quote-escape" : "\\" }
return csv:parse( $values, $options )

(: vim:set syntax=xquery et sw=2 ts=2: :)
