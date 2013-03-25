import module namespace j = "http://jsoniq.org/functions";

(: ebv of a sequence of an object :)
let $j := { "foo" : [ 1 to 10 ], "bar" : true() }
return fn:boolean($j)

