declare namespace ann = "http://zorba.io/annotations";

declare variable $x := 1;

declare %ann:sequential function local:f () 
{
  variable $x := 2;
  $x := $x + 10;
  exit returning $x;
};

$x := $x + 100;
($x, local:f (), $x)
