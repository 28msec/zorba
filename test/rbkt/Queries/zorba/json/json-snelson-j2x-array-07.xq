import module namespace jx = "http://zorba.io/modules/json-xml";

let $json := [ [ 11, 12 ], [ 21, 22 ] ]
return jx:json-to-xml( $json )

(: vim:se et sw=2 ts=2: :)
