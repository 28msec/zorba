import module namespace x = "http://zorba.io/modules/xml#2.1";
 
let $xml := "aaaa"
return x:canonicalize($xml)
