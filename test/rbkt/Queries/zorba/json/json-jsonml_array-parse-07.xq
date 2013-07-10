import module namespace json =
  "http://zorba.io/modules/json-xml";

let $opt :=
  <options xmlns="http://zorba.io/modules/json-xml-options">
    <json-format value="JsonML-array"/>
  </options>
let $json :=
  '{
    "args": [ "<div><span>foo:</span> parse</div>" ]
   }'
return json:parse( $json, $opt )

(: vim:set et sw=2 ts=2: :)
