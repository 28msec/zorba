(: parse an JSON array composed of 2 JSON arrays :)

import module namespace json = "http://zorba.io/modules/json-xml";

json:parse( '[ [ 11, 12 ], [ 21, 22 ] ]' )

(: vim:se et sw=2 ts=2: :)
