for $x in (4,5,1,2,2,3,4,4)
for $y in ('a', 'b', 'c')
group by $x
order by $x
return <r><x>{$x}</x><y>{$y}</y></r>
