import module namespace x = "http://www.zorba-xquery.com/modules/xml#2.1";
 
let $xml := "aaaa"
return x:canonicalize($xml)
