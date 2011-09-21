import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

(refl:eval("declare variable $x := 1; $x")) + $x
