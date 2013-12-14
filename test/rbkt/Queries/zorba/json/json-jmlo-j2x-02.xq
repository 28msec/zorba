(: Multi-level JsonML (object form) :)

import module namespace jx = "http://zorba.io/modules/json-xml";

let $json :=
  {
    "tagName" : "ul",
    "childNodes" : [
      { "tagName" : "li", "childNodes" : [ "list item 1" ] },
      { "tagName" : "li", "childNodes" : [ "list item 2" ] }
    ]
  }
let $options := { "json-format" : "JsonML-object" }
return jx:json-to-xml( $json, $options )

(: vim:set et sw=2 ts=2: :)
