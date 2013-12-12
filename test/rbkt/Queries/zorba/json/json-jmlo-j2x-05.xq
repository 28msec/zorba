jsoniq version "1.0";

import module namespace jx = "http://zorba.io/modules/json-xml";

let $j :=
  {
    "tagName" : "table", 
    "class" : "MyTable", 
    "style" : "background-color:yellow", 
    "childNodes" : [ {
      "tagName" : "tr", 
      "childNodes" : [ {
        "tagName" : "td", 
        "class" : "MyTD", 
        "style" : "border:1px solid black", 
        "childNodes" : [ "#550758" ]
      }, {
        "tagName" : "td", 
        "class" : "MyTD", 
        "style" : "background-color:red", 
        "childNodes" : [ "Example text here" ]
      } ]
    }, {
      "tagName" : "tr", 
      "childNodes" : [ {
        "tagName" : "td", 
        "class" : "MyTD", 
        "style" : "border:1px solid black", 
        "childNodes" : [ "#993101" ]
      }, {
        "tagName" : "td", 
        "class" : "MyTD", 
        "style" : "background-color:green", 
        "childNodes" : [ "127624015" ]
      } ]
    }, {
      "tagName" : "tr", 
      "childNodes" : [ {
        "tagName" : "td", 
        "class" : "MyTD", 
        "style" : "border:1px solid black", 
        "childNodes" : [ "#E33D87" ]
      }, {
        "tagName" : "td", 
        "class" : "MyTD", 
        "style" : "background-color:blue", 
        "childNodes" : [ " ", {
          "tagName" : "span", 
          "style" : "background-color:maroon", 
          "childNodes" : [ "\u00A9" ]
        }, " " ]
      } ]
    } ]
  }
let $options := { "json-format" : "JsonML-object" }
return jx:json-to-xml( $j, $options )

(: vim:se et sw=2 ts=2: :)
