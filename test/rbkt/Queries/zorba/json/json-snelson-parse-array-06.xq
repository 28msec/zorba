(: parse a JSON array composed of 2 JSON objects :)

import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

json:parse( '[ { "key1": "value1" }, { "key2": "value2" } ]' )

(: vim:set et sw=2 ts=2: :)
