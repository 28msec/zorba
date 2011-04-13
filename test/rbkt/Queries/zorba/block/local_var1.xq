declare variable $x := 1;

declare %sequential function local:f () 
{
  declare $x := 2;
  declare $y := $x;
  $y
};

let $y := local:f()
return $y + $x
