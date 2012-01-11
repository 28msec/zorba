for tumbling window $w in (1 to 10)
start $s at $x when true()
only end $e at $y when $y - $x eq 2
return <window>{$w}</window>

