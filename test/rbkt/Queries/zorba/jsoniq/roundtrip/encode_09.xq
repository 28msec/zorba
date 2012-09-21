import schema namespace s = "http://www.zorba-xquery.com/simple" at "simple.xsd";

jn:encode-for-roundtrip({
  "hatSize" : s:HatSizeType("10")
})