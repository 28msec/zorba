import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

declare namespace op = "http://www.zorba-xquery.com/options/features";
declare namespace f = "http://www.zorba-xquery.com/features";

declare option op:enable "f:hof";

let $x := refl:eval("for $i in 1 to 10 return [ 'foo' || $i, 'bar' || $i ]")
return $x()
