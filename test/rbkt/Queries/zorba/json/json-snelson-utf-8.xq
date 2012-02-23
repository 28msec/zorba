(: try parsing a Unicode UTF-8 value :)

import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

json:parse('{"mdash": "–"}')
