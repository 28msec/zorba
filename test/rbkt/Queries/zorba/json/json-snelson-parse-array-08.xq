import module namespace json =
  "http://zorba.io/modules/json-xml";

let $json := '[ 1, { "foo": "bar" } ]'
return json:parse( $json )

(: vim:se et sw=2 ts=2: :)
