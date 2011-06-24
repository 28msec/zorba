import module namespace ref = "http://www.zorba-xquery.com/modules/reflection";

declare function local:plus($param as xs:integer) as xs:integer
{
  $param + 1

};

ref:invoke-simple(xs:QName("local:plus"), 1)
