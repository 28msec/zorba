(: parse an JSON array composed of 2 JSON arrays :)

import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

json:parse( '[ [ 11, 12 ], [ 21, 22 ] ]' )

(: vim:se et sw=2 ts=2: :)
