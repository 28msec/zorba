declare variable $x := 42;

declare sequential function local:f($n) 
{
  declare $x := $n - 1;

  if ($n eq 0)
  then 0
  else (let $y := local:f($x) return $y + $x)
};



let $y := local:f(4)
let $z := local:f(3)
return $y + $z + $x
