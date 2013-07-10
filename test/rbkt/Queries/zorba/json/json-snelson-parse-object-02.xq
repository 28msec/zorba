import module namespace json = "http://zorba.io/modules/json-xml";

let $json := '{ "a" : 1, "b" : 2 }'
return json:parse( $json )

(: vim:set et sw=2 ts=2: :)
