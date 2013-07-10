(: json:parse with uncommon characters :)

import module namespace json = "http://zorba.io/modules/json-xml";

json:parse( '{ "web-app" : "!_\"-\\?*.$+" }' )

(: vim:se et sw=2 ts=2: :)
