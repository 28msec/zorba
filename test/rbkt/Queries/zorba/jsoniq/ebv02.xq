import module namespace j = "http://jsoniq.org/functions";

(: ebv of an array in a pair :)
let $j := { "foo" : [ 1 to 10 ] }
return fn:boolean($j("foo"))
