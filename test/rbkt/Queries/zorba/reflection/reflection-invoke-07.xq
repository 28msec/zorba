import module namespace ref = "http://www.zorba-xquery.com/modules/reflection";

declare function local:recursive($param as xs:integer) as xs:integer
{
  if ($param eq 0)
  then
    42
  else
    ref:invoke-simple(xs:QName("local:recursive"), $param - 1)
};

ref:invoke-simple(xs:QName("local:recursive"), 10)
