
for $j in (1, 2)
let $a :=
  for $i in 1 to 10
  return ($i, { if ($i mod 2 eq 0) then "foo2" else "foo1" : "bar" || $i })
return $a()
