for tumbling window $w1 in
  for tumbling window $w2 in (1 to 10)
  start $s when true()
  only end $e when $e - $s eq 2
  return $w2
start $s when true()
end $e when $e - $s eq 2
return <window>{$w2}</window>
