import module namespace csv = "http://zorba.io/modules/csv";

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
return string-join( csv:serialize( $values ), "" )

(: vim:set syntax=xquery et sw=2 ts=2: :)
