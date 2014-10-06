let $x := function($a, $b, $c) { $a + $b + $c }
let $y := $x(?, 3, ?)
let $z := $y(3, ?)
return
(
    $x(1,2,3),
    $y(4,5),
    $z(6)
)