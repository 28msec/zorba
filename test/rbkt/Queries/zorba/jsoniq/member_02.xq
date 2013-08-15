import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

let $x := refl:eval("for $i in 1 to 10 return [ 'foo' || $i, 'bar' || $i ]")
return $x(1)

