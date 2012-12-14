
let $x := (1 to 100)

for sliding window $w in (2, 4, 6, 8, 10, 12, 14)
    start at $s when fn:true()
    only end at $e when $e - $s eq 2

return <window foo="{$x[$s]}">{ $w }</window>
