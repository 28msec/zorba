import module namespace jx = "http://zorba.io/modules/json-xml";

let $json := [ 1, { "foo" : "bar" } ]
return jx:json-to-xml( $json )

(: vim:se et sw=2 ts=2: :)
