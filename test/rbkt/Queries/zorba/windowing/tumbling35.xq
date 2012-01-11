for $i in 1 to 3
count $r
for tumbling window $w in (1 to 10)
start $s when true()
end $e when $e - $s eq 2
where $w = $r + 1
return <window num="{$r}">{$w}</window>

