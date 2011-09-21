for $x in (1,1,2,3,3,4)
for $y in ('a', 'a', 'b', 'b', 'c')
group by $x, $y
return <r>{($x, $y)}</r>
