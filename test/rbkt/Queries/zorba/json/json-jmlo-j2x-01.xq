(: Simple JsonML (object form) :)

import module namespace jx = "http://zorba.io/modules/json-xml";

let $json :=
  {
    "tagName": "li",
    "childNodes" : [ "list item" ]
  }
let $options := { "json-format" : "JsonML-object" }
return jx:json-to-xml( $json, $options )

(: vim:set et sw=2 ts=2: :)
