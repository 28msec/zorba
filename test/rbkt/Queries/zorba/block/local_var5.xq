
declare variable $x as xs:integer := 1;

declare %sequential function local:f() 
{
  variable $y as xs:integer := 2;
  $x + $y
};


local:f()

