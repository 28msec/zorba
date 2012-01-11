for $x1 in 11
for $x2 in 12
for $x3 in 13
for $x4 in 14
for $x5 in 15
for $x6 in 16
for $x7 in 17
for $x8 in 18
for $x9 in 19
for tumbling window $x1 in (1 to 10)
start $x2 at $x3 previous $x4 next $x5 when true()
end $x6 at $x7 previous $x8 next $x9 when false()
return 
  string-join(
    for $i in ($x1, $x2, $x3, $x4, $x5, $x6, $x7, $x8, $x9)
    return string($i), " "
  )
