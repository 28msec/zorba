import module namespace jx = "http://zorba.io/modules/json-xml";

let $json :=
  {
    "tagName" : "person", 
    "created" : "2006-11-11T19:23", 
    "modified" : "2006-12-31T23:59", 
    "childNodes" : [
      {
        "tagName" : "firstName", 
        "childNodes" : [ "Robert" ]
      },
      {
        "tagName" : "lastName", 
        "childNodes" : [ "Smith" ]
      },
      {
        "tagName" : "address", 
        "type" : "home", 
        "childNodes" : [
          {
            "tagName" : "street", 
            "childNodes" : [ "12345 Sixth Ave" ]
          },
          {
            "tagName" : "city", 
            "childNodes" : [ "Anytown" ]
          },
          {
            "tagName" : "state", 
            "childNodes" : [ "CA" ]
          },
          {
            "tagName" : "postalCode", 
            "childNodes" : [ "98765-4321" ]
          }
        ]
      }
    ]
  }
let $options := { "json-format" : "JsonML-object" }
return jx:json-to-xml( $json, $options )

(: vim:set et sw=2 ts=2: :)
