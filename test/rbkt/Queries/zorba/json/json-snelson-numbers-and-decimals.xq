(: json:parse testing numbers and decimals :)

import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

json:parse('{ "special-numbers": {
         "decimal": 2.89,
         "e": 2E+6,
         "negative": -1.89
      }
    }')
