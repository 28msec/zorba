import module namespace jx = "http://zorba.io/modules/json-xml";

let $json := { "k1" : [ { "k2" : "v2" }, null ] }
return jx:json-to-xml( $json )

(: vim:se et sw=2 ts=2: :)
