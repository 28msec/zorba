import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

declare namespace op = "http://www.zorba-xquery.com/options/features";
declare namespace f = "http://www.zorba-xquery.com/features";

declare option op:enable "f:hof";

let $x := refl:eval("({ 'foo' : 'bar' }, [ 1 ])")
return $x("foo")

