
declare namespace my="foo.com";

declare function my:foo($p as xs:integer*) as xs:boolean*
{
  for $x in $p
  return fn:empty($x)
};

my:foo((1,2,3)), my:foo((1,2)[4])
