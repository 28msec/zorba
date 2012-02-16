import module namespace json =
  "http://www.zorba-xquery.com/modules/converters/json";

let $json := '[ 1, { "foo": "bar" } ]'
return json:parse( $json )

(: vim:se et sw=2 ts=2: :)
