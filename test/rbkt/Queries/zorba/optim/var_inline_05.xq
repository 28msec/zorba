
(: should NOT inline $x :)


let $x := <a><b>1</b><b>2</b></a>

for tumbling window $w in (2, 4, 6, 8, 10, 12)
    start at $s when fn:true()
    only end at $e when $e - $s eq xs:integer($x/b[2])

return <window>{ $w }</window>
