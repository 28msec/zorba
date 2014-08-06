import module namespace jx = "http://zorba.io/modules/json-xml";

let $json :=
  {
    "tagName" : "ul",
    "childNodes" : [
      {
        "tagName" : "li",
        "style" : "color:red",
        "childNodes" : [ "First Item" ]
      },
      {
        "tagName" : "li",
        "title" : "Some hover text.",
        "style" : "color:green",
        "childNodes" : [ "Second Item" ]
      },
      {
        "tagName" : "li",
        "childNodes" : [
          {
            "tagName" : "span",
            "class" : "code-example-third",
            "childNodes" : [ "Third" ]
          },
          " Item"
        ]
      }
    ]
  }
let $options := { "json-format" : "JsonML-object" }
return jx:json-to-xml( $json, $options )

(: vim:se et sw=2 ts=2: :)
