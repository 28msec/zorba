let $obj := {
              "nan" : xs:double("NaN"),
              "inf" : xs:double("INF"),
              "date" : xs:date("1066-10-14"),
              "QName" : xs:QName("jn:encode-for-roundtrip"),
              "EQName" : fn:QName("http://jsoniq.org/roundtrip", "value")
            }
let $enc := jn:encode-for-roundtrip($obj)
let $dec := jn:decode-from-roundtrip($enc)
return jn:encode-for-roundtrip($dec)
