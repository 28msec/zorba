import module namespace jx = "http://zorba.io/modules/json-xml";

let $json := '
  [ "ul",
    [ "li", true ],
    [ "li", { "href" : "driving.html", "title" : "Driving" }, "Second item" ],
    [ "li", null ],
    [ "li", -14e12 ]
' (: missing closing ']' :)
return jx:json-string-to-xml( $json )

(: vim:set et sw=2 ts=2: :)
