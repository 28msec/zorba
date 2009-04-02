declare variable $x := 1;
declare sequential function local:f () {
  declare variable $x := 2;
  declare variable $y := $x;
  $y
};

local:f () + $x
