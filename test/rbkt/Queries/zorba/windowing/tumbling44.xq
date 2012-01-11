for tumbling window $w as xs:string in (1 to 10)
start $s when true()
end $e when $e - $s eq 3
return <window>{$w}</window>
