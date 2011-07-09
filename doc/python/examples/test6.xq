declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare variable $x := 42;

declare %ann:sequential function local:f($n) 
{
  variable $x := $n - 1;

  if ($n eq 0)
  then 0
  else { variable $y := local:f($x); ($y + $x) }
};


{
  variable $y := local:f(4);
  variable $z := local:f(3);
  $y + $z + $x
}
