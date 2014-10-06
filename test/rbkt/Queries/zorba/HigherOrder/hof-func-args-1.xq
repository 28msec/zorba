let $x := function($a, $b) { $a + $b }
let $y := $x(?, 3)
let $z := $x(3, ?)
return
(
    $x(2, 2),
    $y(2),
    $z(3)
)