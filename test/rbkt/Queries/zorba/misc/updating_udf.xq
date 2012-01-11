

declare function local:foo($x) as xs:boolean
{
  $x
};


declare updating function local:delete($n as node(), $x as xs:boolean)
{
  if (local:foo($x))
  then delete node $n
  else delete node $n
};

declare variable $doc := <root><a id="1"/><a id="2"/><a id="3"/><a id="4"/></root>;

{
  for $node in $doc/a
  return local:delete($node, fn:true());

  $doc
}

