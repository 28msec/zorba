import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

let $x := refl:eval("()")
return $x("foo")
