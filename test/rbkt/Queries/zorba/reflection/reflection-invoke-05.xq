import module namespace ref = "http://zorba.io/modules/reflection";

declare function local:plus($param as xs:integer*) as xs:integer*
{
  for $i in $param
  return $i + 1
};

ref:invoke(xs:QName("local:plus"), (1, 2, 3))
