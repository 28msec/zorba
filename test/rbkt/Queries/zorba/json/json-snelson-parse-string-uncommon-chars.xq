import module namespace jx = "http://zorba.io/modules/json-xml";

let $json := '{ "web-app" : "!_\"-\\?*.$+" }'
return jx:json-string-to-xml( $json )

(: vim:se et sw=2 ts=2: :)
