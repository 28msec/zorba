for $x in (1,1,2)
let $y := $x
for $z in ('a','a','b')
group by $y
return <r><x>{$x}</x><y>{$y}</y><z>{$z}</z></r>
