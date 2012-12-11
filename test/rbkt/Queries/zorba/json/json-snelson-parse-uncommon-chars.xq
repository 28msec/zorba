(: json:parse with uncommon characters :)

import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

json:parse( '{ "web-app" : "!_\"-\\?*.$+" }' )

(: vim:se et sw=2 ts=2: :)
