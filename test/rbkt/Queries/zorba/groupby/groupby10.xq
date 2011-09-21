for $x in ('a', 'b', 'c')
let $y := <a>1</a>
group by $y
return <r><x>{$x}</x><y>{$y}</y></r>
