
declare variable $g := 3;

for $x in (1, 2, 3)
let $y := $x mod 2
return let $foo := $g where sum(for $z in (5, $foo) return $z * $y + $foo) > 8 return $x
