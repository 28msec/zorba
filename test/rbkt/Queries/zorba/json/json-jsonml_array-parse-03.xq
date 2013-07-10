import module namespace json = "http://zorba.io/modules/json-xml";

let $json := '
  [ "file",
    {
      "dir" : "/tmp",
      "name" : "foo",
      "size" : 1234,
      "modified" : "2006-12-31T23:59"
    }
  ]
'
let $options :=
  <options xmlns="http://zorba.io/modules/json-xml-options">
    <json-format value="JsonML-array"/>
  </options>
return json:parse( $json, $options )

(: vim:set et sw=2 ts=2: :)
