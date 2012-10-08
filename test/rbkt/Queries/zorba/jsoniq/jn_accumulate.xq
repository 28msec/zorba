import module namespace libjn = "http://jsoniq.org/function-library";

declare variable $xdoc :=
<nodes>
<node>10</node>
<node>20</node>
</nodes>;

variable $obj :=
libjn:accumulate(
  for $node at $pos in $xdoc//node
  return { concat("n", $pos) : $node }
);

jn:encode-for-roundtrip($obj, { "prefix" : "" })
