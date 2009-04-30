for $x in (1,1,2,3,3,4)
for $y in ('a', 'a', 'b', 'b', 'c')
group by $x
return <r><x>{$x}</x><y>{$y}</y></r>
