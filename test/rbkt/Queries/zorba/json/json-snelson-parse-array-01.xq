import module namespace json = "http://zorba.io/modules/json-xml";

let $json := '[ true ]'
return json:parse( $json )

(: vim:set et sw=2 ts=2: :)
