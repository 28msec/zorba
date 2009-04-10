declare variable $x := 42;
declare sequential function local:f ($n) {
  declare $x := $n - 1;
  if ($n eq 0)
    then 0
    else local:f ($x) + $x
};

local:f (4) + local:f (3) + $x
