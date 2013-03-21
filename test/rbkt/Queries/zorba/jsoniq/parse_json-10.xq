let $json := '[ 1, 2 ][ 3, 4 ]'
let $options := {
  "jsoniq-multiple-top-level-items" : true(),
  "jsoniq-strip-top-level-array" : true()
}
return jn:parse-json( $json, $options )

(: vim:set et sw=2 ts=2: :)
