import module namespace json =
  "http://www.zorba-xquery.com/modules/converters/json";

let $json := '{ "k1" : [ { "k2" : "v2" }, null ] }'
return json:parse( $json )

(: vim:se et sw=2 ts=2: :)
