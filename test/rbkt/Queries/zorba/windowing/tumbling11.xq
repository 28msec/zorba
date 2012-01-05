for tumbling window $w in (1 to 10)
start $s when true()
end $e when $e - $w eq 2
return <window>{$w}</window>
