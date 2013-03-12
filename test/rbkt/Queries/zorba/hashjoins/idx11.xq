


for $x in (1, 2, 3)
let $y := (1, 2)
for $z in (1, 2, 2, 3)[. ge count($y)] 
where $x eq $z
return $z
