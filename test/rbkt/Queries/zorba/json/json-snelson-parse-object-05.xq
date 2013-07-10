(: json:parse testing null as a key value :)

import module namespace json = "http://zorba.io/modules/json-xml";

json:parse( '{ "a" : null }' )

(: vim:set et sw=2 ts=2: :)
