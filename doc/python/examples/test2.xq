for $x in (3, 1, 2)
count $m
order by $x
count $n
let $delta := $n - $m
return <r><x>{$x}</x><m>{$m}</m><n>{$n}</n><d>{$delta}</d></r>
