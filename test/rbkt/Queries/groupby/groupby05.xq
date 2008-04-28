for $x in (1,1,2,3,3,4)
for $y in ('a', 'b', 'c')
group by $x
where $x = (1,2)
return <r><x>{$x}</x><y>{$y}</y></r>
