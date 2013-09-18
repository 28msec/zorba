(: try parsing a valid JSON string with an invalid JSON $options parameter :)

import module namespace jx = "http://zorba.io/modules/json-xml";

let $json := '{}'
let $options := { "json-format" : "array" }
return jx:json-string-to-xml( $json, $options )
