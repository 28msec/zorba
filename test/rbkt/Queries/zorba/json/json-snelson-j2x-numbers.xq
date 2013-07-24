import module namespace jx = "http://zorba.io/modules/json-xml";

let $json := {
  "decimal" : 2.89,
  "e" : 2E+6,
  "negative" : -1.89
}
return jx:json-to-xml( $json )

(: vim:se et sw=2 ts=2: :)
