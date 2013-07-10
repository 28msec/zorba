import module namespace json =
  "http://zorba.io/modules/json-xml";

let $json := '{ "k1" : [ { "k2" : "v2" }, null ] }'
return json:parse( $json )

(: vim:se et sw=2 ts=2: :)
