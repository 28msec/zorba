import module namespace ref = "http://zorba.io/modules/reflection";

declare function local:recursive($param as xs:integer) as xs:integer
{
  if ($param eq 0)
  then
    42
  else
    local:recursive($param - 1)
};

ref:invoke(xs:QName("local:recursive"), 10)
