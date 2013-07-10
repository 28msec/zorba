(: parse a JSON array composed of 2 JSON objects :)

import module namespace json = "http://zorba.io/modules/json-xml";

json:parse( '[ { "key1": "value1" }, { "key2": "value2" } ]' )

(: vim:set et sw=2 ts=2: :)
