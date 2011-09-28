"",
for $x in (1 to 2)
  for $y allowing empty at $j in ($x to 1)
    return ($x, ",", $y, ",", $j,"
")
