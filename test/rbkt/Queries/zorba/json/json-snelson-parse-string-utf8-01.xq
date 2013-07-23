(: Try parsing a UTF-8 value :)

import module namespace jx = "http://zorba.io/modules/json-xml";

let $json := '{ "mdash": "–" }'
return jx:json-string-to-xml( $json )
