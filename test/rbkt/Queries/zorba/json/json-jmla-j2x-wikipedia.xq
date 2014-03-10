import module namespace jx = "http://zorba.io/modules/json-xml";

let $json :=
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
let $options := { "json-format" : "JsonML-array" }
return jx:json-to-xml( $json, $options )

(: vim:set et sw=2 ts=2: :)
