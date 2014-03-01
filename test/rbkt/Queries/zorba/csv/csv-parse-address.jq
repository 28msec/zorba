import module namespace csv = "http://zorba.io/modules/json-csv";

let $csv := "870 Market Street"
let $options := { "field-names" : [ "Street" ] }
return csv:parse( $csv, $options )

(: vim:set syntax=xquery et sw=2 ts=2 :)
