import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

let $json := '
  [ "person",
    { "created" : "2006-11-11T19:23",
      "modified" : "2006-12-31T23:59" },
    [ "firstName", "Robert" ],
    [ "lastName", "Smith" ],
    [ "address",
      { "type" : "home" },
      [ "street", "12345 Sixth Ave" ],
      [ "city", "Anytown" ],
      [ "state", "CA" ],
      [ "postalCode", "98765-4321" ]
    ]
  ]
'
let $options :=
  <options xmlns="http://www.zorba-xquery.com/modules/converters/json-options">
    <json-format value="JsonML-array"/>
  </options>
return json:parse( $json, $options )
(: vim:set et sw=2 ts=2: :)
