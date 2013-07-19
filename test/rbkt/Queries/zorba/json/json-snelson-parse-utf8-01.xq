import module namespace jx = "http://zorba.io/modules/json-xml";

let $json := { "mdash" : "–" }
return jx:json-to-xml( $json )
