import module namespace jn = "http://www.jsoniq.org/functions";

declare variable $xdoc :=
<nodes>
<node>10</node>
<node>20</node>
</nodes>;

variable $obj :=  
jn:accumulate( 
  for $node at $pos in $xdoc//node 
  return { concat("n", $pos) : $node } 
);

$obj

