for $x in (<a/>,<b/>)
return 
for $y in ('a', 'b', 'b', 'c')
for $z in (1,2)
group by $y
return <r><x>{$x}</x><y>{$y}</y><z>{$z}</z></r>
