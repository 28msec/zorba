(: try parsing a valid JSON string with invalid JSON option parameter :)

import module namespace json = "http://zorba.io/modules/json-xml";

let $options := { "json-format" : "array" }
return json:parse('{}',$options)
