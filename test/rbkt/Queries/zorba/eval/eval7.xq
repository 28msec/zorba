import module namespace refl = "http://zorba.io/modules/reflection";

declare variable $s :=
'module namespace math = "http://example.org/math-functions";
 declare variable $math:pi := 3.14;';

refl:eval($s)
