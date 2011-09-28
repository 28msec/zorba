for tumbling window $w in (2, 4, 6, 8, 10, 12, 14)
    start $first at $s when fn:true()
    only end $last at $e when $e - $s eq 2
return <window>{ $first, $last }</window>
