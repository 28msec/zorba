(: Test "quote-char" with a string > 1 character in length. :)

import module namespace csv = "http://zorba.io/modules/json-csv";
import module namespace file = "http://expath.org/ns/file";

declare variable $rbktPath as xs:string external;

let $file := concat( $rbktPath, "/Queries/zorba/csv/sample_files/csv-quote-char-01.csv" )
let $values := file:read-text( $file )
let $options := { "quote-char" : "''" }
return csv:parse( $values, $options )

(: vim:set syntax=xquery et sw=2 ts=2: :)
