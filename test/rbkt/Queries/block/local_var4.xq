declare variable $x := 100;

declare sequential function local:f ($n) {
  declare variable $x := $n;
  set $x := $x - 1;
  if ($n eq 0)
    then -1
    else ($x, local:f ($x), $x);
};

local:f (3), $x
