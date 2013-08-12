let $json := '[ 1, 2 ]'
let $options := { "jsoniq-strip-top-level-array" : true() }
return jn:parse-json( $json, $options )

(: vim:set et sw=2 ts=2: :)
