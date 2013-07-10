(: try parsing a Unicode UTF-8 value :)

import module namespace json = "http://zorba.io/modules/json-xml";

json:parse( '{ "mdash": "–" }' )
