import module namespace jx = "http://zorba.io/modules/json-xml";

let $json := { "a" : 1, "b" : 2 }
return jx:json-to-xml( $json )

(: vim:set et sw=2 ts=2: :)
