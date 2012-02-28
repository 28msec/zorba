for sliding window $w in (1 to 10)
start $s when true()
only end $e when $e - $s eq 2
order by $w[2] descending
return <window>{$w}</window>
