
declare function local:remove-identifiers($nodes as node()*) as node()*
{
  for $node in $nodes
  return
    copy $node-clean:=$node
    modify
    (

    )
    return $node-clean
};


let $doc:=doc("data.xml")
return local:remove-identifiers($doc) 
