

declare variable $doc :=
<root>
<n1/>
<n2/>
</root>;


declare function local:boo()
{
};


declare function local:foo($nodes as node()*)
{
  for $n in $nodes 
  return count(($n/following-sibling::*[1])/*)
};


local:foo(for $node in $doc/*
          return 
          {
            insert node <a/> as first into $node; 
            $node
          })
