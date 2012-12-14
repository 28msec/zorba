let $o := { "a" : 5, "b" : 6 }
let $a := $o("a")
let $b := $o("b")
return { $a, $b }
