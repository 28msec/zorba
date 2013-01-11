import module namespace x = "http://www.zorba-xquery.com/modules/xml";
 
let $xml := "aaaa"
return x:canonicalize($xml)
