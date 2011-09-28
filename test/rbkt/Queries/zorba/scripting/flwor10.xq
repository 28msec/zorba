

variable $x := 0;

for $i in (1, 2, 3)
let $y := { $x := $x + $i; }
return $x
