import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

let $json := '[ true ]'
return json:parse( $json )
(: vim:set et sw=2 ts=2: :)
