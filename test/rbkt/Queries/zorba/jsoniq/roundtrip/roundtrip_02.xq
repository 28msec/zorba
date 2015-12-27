import module namespace r = "http://zorba.io/modules/random";

import schema namespace o = "http://www.w3.org/2010/xslt-xquery-serialization";

variable $obj := {
              "nan" : xs:double("NaN"),
              "inf" : xs:double("INF"),
              "date" : xs:date("1066-10-14"),
              "QName" : xs:QName("jn:encode-for-roundtrip"),
              "EQName" : fn:QName("http://jsoniq.org/roundtrip", "value")
            };
variable $enc := jn:encode-for-roundtrip($obj);
variable $serialized := serialize($enc, <o:serialization-parameters><o:method value="json"/></o:serialization-parameters>);
variable $dec := jn:decode-from-roundtrip(jn:parse-json($serialized));

(
  $dec("nan") instance of xs:double and xs:string($dec("nan")) eq "NaN",
  $dec("inf") instance of xs:double and xs:string($dec("inf")) eq "INF",
  $dec("date") instance of xs:date and year-from-date($dec("date")) eq 1066,
  $dec("QName") instance of xs:QName and prefix-from-QName($dec("QName")) eq "jn",
  $dec("EQName") instance of xs:QName and namespace-uri-from-QName($dec("EQName")) eq "http://jsoniq.org/roundtrip"
)
