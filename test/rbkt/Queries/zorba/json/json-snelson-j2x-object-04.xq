import module namespace jx = "http://zorba.io/modules/json-xml";

let $json :=
  {
    "key1": [ 1 ],
    "key2": "value"
  }
return jx:json-to-xml( $json )

(: vim:se et sw=2 ts=2: :)
