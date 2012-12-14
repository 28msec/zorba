let $seq := (xs:double("NaN"), 5, 1.2, "string", xs:QName("xs:QName"))
let $enc := jn:encode-for-roundtrip($seq)
return [
  $enc[1] instance of object(),
  $enc[2] instance of xs:integer,
  $enc[3] instance of xs:decimal,
  $enc[4] instance of xs:string,
  $enc[5] instance of object(),
  jn:decode-from-roundtrip($enc)
]