

declare function local:foo($n as node(), $level as xs:integer) as node()
{
  if ($level > 0)
  then
    local:foo(<a xmlns:foo="foo.com">{$n}</a>, $level - 1)
  else
    $n
};



in-scope-prefixes(local:foo(<b/>, 4)//b)
