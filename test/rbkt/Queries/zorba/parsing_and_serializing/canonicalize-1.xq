import module namespace x = "http://zorba.io/modules/xml";

let $xml := "<x b='1' a='2'/>"
return x:canonicalize($xml)
