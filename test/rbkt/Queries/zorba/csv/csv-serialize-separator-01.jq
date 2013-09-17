import module namespace csv = "http://zorba.io/modules/json-csv";

let $values := (
  {
    "first" : "one",
    "second" : "two",
    "third" : "three"
  },
  {
    "first" : "four",
    "second" : "embedded \" quote",
    "third" : "embedded\r\nnewline"
  }
)
let $options := {
  "field-names" : [ "first", "second", "third" ],
  "separator" : "|"
}
return string-join( csv:serialize( $values, $options ), "" )

(: vim:set syntax=xquery et sw=2 ts=2: :)
