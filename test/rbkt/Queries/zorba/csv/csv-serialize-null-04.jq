import module namespace csv = "http://zorba.io/modules/json-csv";

let $values := (
  {
    "bar" : null
  }
)
let $options := {
  "serialize-null-as" : ""
}
return string-join( csv:serialize( $values, $options ), "" )

(: vim:set syntax=xquery et sw=2 ts=2: :)
