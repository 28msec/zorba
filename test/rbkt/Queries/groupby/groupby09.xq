for $x in (<a>1</a>, <b>2</b>, <c>1</c>, <d>4</d>)
let $y := ('a', 'b', 'c')
for $z in (1,2)
group by $x
return <r><x>{$x}</x><y>{$y}</y><z>{$z}</z></r>
