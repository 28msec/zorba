import module namespace refl = "http://zorba.io/modules/reflection";

let $x := refl:eval("for $i in 1 to 10 return [ 'foo' || $i, 'bar' || $i ]")
return $x()
