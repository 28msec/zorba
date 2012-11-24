(: json:parse testing null as a key value :)

import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

json:parse( '{ "a" : null }' )

(: vim:set et sw=2 ts=2: :)
