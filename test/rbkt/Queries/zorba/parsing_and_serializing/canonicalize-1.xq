import module namespace parse-xml = "http://www.zorba-xquery.com/modules/xml";

let $xml := "<x b='1' a='2'/>"
return parse-xml:canonicalize($xml)
