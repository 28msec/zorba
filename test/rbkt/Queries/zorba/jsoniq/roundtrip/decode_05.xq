let $objs := jn:decode-from-roundtrip((
  {
    "nan" : {
      "Q{http://jsoniq.org/roundtrip}type" : "xs:double",
      "Q{http://jsoniq.org/roundtrip}value" : "NaN"
    },
    "inf" : {
      "Q{http://jsoniq.org/roundtrip}type" : "xs:double",
      "Q{http://jsoniq.org/roundtrip}value" : "INF"
    }
  }, {
    "date" : {
      "Q{http://jsoniq.org/roundtrip}type" : "xs:date",
      "Q{http://jsoniq.org/roundtrip}value" : "1066-10-14"
    }
  }, {
    "QName" : {
      "Q{http://jsoniq.org/roundtrip}type" : "xs:QName",
      "Q{http://jsoniq.org/roundtrip}value" : "Q{http://jsoniq.org/functions}encode-for-roundtrip",
      "Q{http://jsoniq.org/roundtrip}prefix" : "jn"
    },
    "EQName" : {
      "Q{http://jsoniq.org/roundtrip}type" : "xs:QName",
      "Q{http://jsoniq.org/roundtrip}value" : "Q{http://jsoniq.org/roundtrip}value"
    }
  }))
let $doub := $objs[1]
let $date := $objs[2]
let $qnam := $objs[3]
return
  (
    $doub("nan") instance of xs:double and xs:string($doub("nan")) eq "NaN",
    $doub("inf") instance of xs:double and xs:string($doub("inf")) eq "INF",
    $date("date") instance of xs:date and year-from-date($date("date")) eq 1066,
    $qnam("QName") instance of xs:QName and prefix-from-QName($qnam("QName")) eq "jn",
    $qnam("EQName") instance of xs:QName and namespace-uri-from-QName($qnam("EQName")) eq "http://jsoniq.org/roundtrip"
  )
