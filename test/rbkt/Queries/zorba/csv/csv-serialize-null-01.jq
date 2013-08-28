import module namespace csv = "http://zorba.io/modules/json-csv";

let $values := (
  {
    "foo" : "f",
    "bar" : null,
    "baz" : "b"
  }
)
let $options := {
  "field-names" : [ "foo", "bar", "baz" ],
  "serialize-null-as" : "null"
}
return string-join( csv:serialize( $values, $options ), "" )

(: vim:set syntax=xquery et sw=2 ts=2: :)
