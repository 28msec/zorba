import module namespace j = "http://www.jsoniq.org/functions";

(: ebv of a the value of a pair :)
let $j := { "foo" : 1 , "bar" : true }
return fn:boolean(j:pairs($j)[1])
