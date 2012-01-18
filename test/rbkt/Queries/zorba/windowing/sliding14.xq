for tumbling window $w in (1 to 10)
start $s when true()
only end $e when $e - $s eq 2
count $r
return
  <window num="{$r}">
  {
    for $i in $w
    order by $i descending
    return $i
  }
  </window>
