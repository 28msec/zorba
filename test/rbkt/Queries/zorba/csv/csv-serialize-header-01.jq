import module namespace csv = "http://zorba.io/modules/csv";

let $values := (
  { "field" : "one" },
  { "field" : "two" }
)
let $options := { "serialize-header" : false }
return string-join( csv:serialize( $values, $options ), "" )

(: vim:set syntax=xquery et sw=2 ts=2: :)
