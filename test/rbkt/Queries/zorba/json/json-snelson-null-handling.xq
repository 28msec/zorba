(: json:parse testing null handling :)

import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

json:parse('{ "web-app": null }')
