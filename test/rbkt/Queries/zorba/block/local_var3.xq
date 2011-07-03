declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare variable $x := 5;

declare variable $result := ();

declare %ann:sequential function local:f($n) 
{
  variable $x := 42, $y := $n;

  for $i in (1, 2)
  return
    {
      variable $dummy := {$x := $i + $y; };
      $x
    }
};


for $i in (10, 20, 30)
return
  {
    variable $dummy := { $result := local:f($i); };
    $result
  }


(:

Note: this query is not equivalent to the above one. The result of this query is:

32, 32, 32, 32, 32, 32

declare variable $x := 5;

declare variable $result := ();

declare %ann:sequential function local:f($n) 
{
  declare $x := 42, $y := $n;

  for $i in (1, 2)
  let $dummy := (set $x := $i + $y)
  return $x
};


for $i in (10, 20, 30)
let $dummy := (set $result := local:f($i))
return $result

:)
