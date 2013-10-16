import module namespace refl = "http://zorba.io/modules/reflection";

declare context item := <doc><a/></doc>;

declare variable $x := <b/>;

refl:eval("
declare context item := <doc><a/><a/></doc>;
declare variable $y := <c/>;
(./a, $x, $y)
")
