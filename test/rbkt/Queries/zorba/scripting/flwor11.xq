

variable $x := 0;

let $y := { $x := $x + 1; () }
for $i in (1, 2, 3)
return $x + $i
