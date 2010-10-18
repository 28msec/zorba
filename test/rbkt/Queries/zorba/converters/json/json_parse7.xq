(: json:parse testing numbers and decimals :)

import module namespace json = "http://www.zorba-xquery.com/modules/json";

declare variable $local:json :=
   '{ "special-numbers": {
         "decimal": 2.89,
         "e": 2E+6,
         "negative": -1.89
      }
    }';

json:parse($local:json)

