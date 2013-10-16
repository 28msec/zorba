import module namespace refl = "http://zorba.io/modules/reflection";

(refl:eval("declare variable $x := 1; $x")) + $x
