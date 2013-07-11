(: jx:json-to-xml testing numbers :)

import module namespace jx = "http://zorba.io/modules/json-xml";

jx:json-to-xml( '{
  "decimal": 2.89,
  "e": 2E+6,
  "negative": -1.89
}' )

(: vim:se et sw=2 ts=2: :)
