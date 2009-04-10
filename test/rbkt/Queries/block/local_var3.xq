declare variable $x := 5;
declare variable $result := ();

declare sequential function local:f ($n) {
  declare $x := 42, $y := $n;
  for $i in (1, 2)
    let $dummy := (set $x := $i + $y)
    return $x
};

for $i in (10, 20, 30)
  let $dummy := (set $result := local:f ($i))
  return $result
