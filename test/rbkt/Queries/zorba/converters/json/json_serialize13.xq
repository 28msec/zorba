(: serializing parsed json differs from the original :)

import module namespace json = "http://www.zorba-xquery.com/modules/json";

declare variable $local:json :=
   '{ "special-chars": {
         "unicode": "\u007B",
         "quote": "\"",
         "backslash": "\\",
         "backspace": "\b",
         "formfeed": "\f",
         "newline": "\n",
         "carriage return": "\r",
         "horizontal tab": "\t",
         "solidus": "\/"
      }
    }';

json:serialize(json:parse($local:json))