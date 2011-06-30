declare variable $x := 1;

declare %sequential function local:f () 
{
  variable $x := 2;
  variable $y := $x;
  $y
};

let $y := local:f()
return $y + $x
