declare namespace ann = "http://zorba.io/annotations";

declare variable $x := 1;

declare function local:f() 
{
  variable $x := 2;
  variable $y := $x;
  $y
};

let $y := local:f()
return $y + $x
