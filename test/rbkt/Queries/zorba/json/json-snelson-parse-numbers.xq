(: json:parse testing numbers :)

import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

json:parse( '{
  "decimal": 2.89,
  "e": 2E+6,
  "negative": -1.89
}' )

(: vim:se et sw=2 ts=2: :)
