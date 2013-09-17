import module namespace csv = "http://zorba.io/modules/json-csv";

let $values := (
  {
    "b1" : true,
    "b2" : false
  }
)
let $options := {
  "field-names" : [ "b1", "b2" ],
  "serialize-boolean-as" : { "true" : "T", "false" : "F" }
}
return string-join( csv:serialize( $values, $options ), "" )

(: vim:set syntax=xquery et sw=2 ts=2: :)
