for tumbling window $w in (1,1,1,1,1,4,2,2,2,2,2,2,4,3,3,3,3,3,4)
start $s when true()
end $e when $e = 4
return <window>{fn:subsequence($w, 1, 3)}</window> 
