for $x in (4,5,1,2,2,3,4,4)
for $y in ('a', 'b', 'c')
group by $x
where $x = (1,2,3)
order by $x descending
return <r><x>{$x}</x><y>{$y}</y></r>
