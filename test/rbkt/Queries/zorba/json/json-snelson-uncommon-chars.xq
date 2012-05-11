(: json:parse with uncommon characters :)

import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

json:parse('{ "web-app": "!_\"-\\?*.$+" }')
