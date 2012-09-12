declare function 
local:collapse-nodes($x as node()*, $id as xs:integer) as node()*
{
  for $y in $x
  let $n := node-name($y)
  group by $n
  order by xs:string($n)
  count $i
  return local:collapse-nodes-same-name($y, $id+1)
};


declare function 
local:collapse-nodes-same-name($x as node()+, $id as xs:integer) as node()
{
  let $f:= $x[1]
  let $n := node-name($f)
  return
      element { $n } 
              { $id,
                local:collapse-nodes($x/*, $id+1)
              }
};



local:collapse-nodes(doc("books.xml")/*, 0)
