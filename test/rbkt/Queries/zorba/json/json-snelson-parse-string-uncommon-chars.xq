(: jx:json-string-to-xml with uncommon characters :)

import module namespace jx = "http://zorba.io/modules/json-xml";

jx:json-string-to-xml( '{ "web-app" : "!_\"-\\?*.$+" }' )

(: vim:se et sw=2 ts=2: :)
