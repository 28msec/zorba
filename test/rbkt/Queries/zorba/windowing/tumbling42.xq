for tumbling window $w in (1 to 10)
start $s at $x as xs:integer when true()
end $e when $e - $s eq 3
return <window>{$w}</window>
