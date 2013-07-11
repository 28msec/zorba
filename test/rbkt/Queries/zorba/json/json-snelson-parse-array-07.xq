(: parse an JSON array composed of 2 JSON arrays :)

import module namespace jx = "http://zorba.io/modules/json-xml";

jx:json-to-xml( '[ [ 11, 12 ], [ 21, 22 ] ]' )

(: vim:se et sw=2 ts=2: :)
