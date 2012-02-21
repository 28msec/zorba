import module namespace json =
  "http://www.zorba-xquery.com/modules/converters/json";

let $json := '
  {
    "key1": [ 1 ],
    "key2": "value"
  }
'
return json:parse( $json )

(: vim:se et sw=2 ts=2: :)
