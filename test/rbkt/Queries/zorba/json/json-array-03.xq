import module namespace json = "http://www.zorba-xquery.com/modules/converters/json#2";

let $json := '[ null ]'
return json:parse( $json )
(: vim:set et sw=2 ts=2: :)
