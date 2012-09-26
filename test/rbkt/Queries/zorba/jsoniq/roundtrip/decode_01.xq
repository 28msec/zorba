let $obj := jn:decode-from-roundtrip(
  {
    "nan" : {
      "Q{http://jsoniq.org/roundtrip}type" : "xs:double",
      "Q{http://jsoniq.org/roundtrip}value" : "NaN"
    },
    "inf" : {
      "Q{http://jsoniq.org/roundtrip}type" : "xs:double",
      "Q{http://jsoniq.org/roundtrip}value" : "INF"
    },
    "date" : {
      "Q{http://jsoniq.org/roundtrip}type" : "xs:date",
      "Q{http://jsoniq.org/roundtrip}value" : "1066-10-14"
    },
    "QName" : {
      "Q{http://jsoniq.org/roundtrip}type" : "xs:QName",
      "Q{http://jsoniq.org/roundtrip}value" : "Q{http://jsoniq.org/functions}encode-for-roundtrip",
      "Q{http://jsoniq.org/roundtrip}prefix" : "jn"
    },
    "EQName" : {
      "Q{http://jsoniq.org/roundtrip}type" : "xs:QName",
      "Q{http://jsoniq.org/roundtrip}value" : "Q{http://jsoniq.org/roundtrip}value"
    }
  })
return
  (
    $obj("nan") instance of xs:double and xs:string($obj("nan")) eq "NaN",
    $obj("inf") instance of xs:double and xs:string($obj("inf")) eq "INF",
    $obj("date") instance of xs:date and year-from-date($obj("date")) eq 1066,
    $obj("QName") instance of xs:QName and prefix-from-QName($obj("QName")) eq "jn",
    $obj("EQName") instance of xs:QName and namespace-uri-from-QName($obj("EQName")) eq "http://jsoniq.org/roundtrip"
  )
