import module namespace csv = "http://zorba.io/modules/json-csv";

let $values := (
  { "field" : "embedded ' quote" }
)
let $options := { "quote-char" : "'" }
return string-join( csv:serialize( $values, $options ), "" )

(: vim:set syntax=xquery et sw=2 ts=2: :)
