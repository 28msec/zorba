import module namespace ref = "http://zorba.io/modules/reflection";

declare function local:plus($param as xs:integer) as xs:integer
{
  $param + 1

};

ref:invoke(xs:QName("local:plus"), "text")
