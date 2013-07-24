import module namespace x = "http://zorba.io/modules/xml";
 
let $xml := "aaaa"
return x:canonicalize($xml)
