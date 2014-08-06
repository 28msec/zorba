import module namespace csv = "http://zorba.io/modules/json-csv";

let $options := { "serialize-header" : false }
return string-join(
  for $i in 1 to 3
  let $o := { "foo" : $i }
  return csv:serialize( $o, $options )
)

(: vim:set et sw=2 ts=2: :)
