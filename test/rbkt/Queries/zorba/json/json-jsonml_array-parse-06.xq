(: try parsing an empty value :)

import module namespace json = "http://zorba.io/modules/json-xml";

let $options := { "json-format" : "JsonML-array" }
return json:parse( <a/>, $options )

(: vim:set et sw=2 ts=2: :)
