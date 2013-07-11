import module namespace jx =
  "http://zorba.io/modules/json-xml";

let $options := { "json-format" : "JsonML-array" }
let $json :=
  '{
    "args": [ "<div><span>foo:</span> parse</div>" ]
   }'
return jx:json-to-xml( $json, $options )

(: vim:set et sw=2 ts=2: :)
