(: try parsing a Unicode UTF-8 value :)

import module namespace jx = "http://zorba.io/modules/json-xml";

jx:json-string-to-xml( '{ "mdash": "–" }' )
