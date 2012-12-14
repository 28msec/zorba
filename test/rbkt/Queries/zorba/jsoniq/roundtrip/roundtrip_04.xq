import schema namespace s = "http://www.zorba-xquery.com/simple" at "simple.xsd";

let $encoded := jn:encode-for-roundtrip({
      "hatSize" : s:HatSizeType("10")
    })
let $decoded := jn:decode-from-roundtrip($encoded)
return
  ($decoded, $decoded("hatSize") instance of s:HatSizeType)