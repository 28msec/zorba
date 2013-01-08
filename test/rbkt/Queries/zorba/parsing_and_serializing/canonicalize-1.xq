import module namespace x = "http://www.zorba-xquery.com/modules/xml";

let $xml := "<x b='1' a='2'/>"
return x:canonicalize($xml)
