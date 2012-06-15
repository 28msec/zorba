declare variable $xdoc :=
<nodes>
<node>10</node>
<node>20</node>
</nodes>;

variable $obj :=  
{| 
  for $node at $pos in $xdoc//node 
  return { concat("n", $pos) : $node } 
|};

$obj

