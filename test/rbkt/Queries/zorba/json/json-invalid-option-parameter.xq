(: try parsing a valid JSON string with invalid JSON option parameter :)

import module namespace jx = "http://zorba.io/modules/json-xml";

let $options := { "json-format" : "array" }
return jx:json-to-xml('{}',$options)
