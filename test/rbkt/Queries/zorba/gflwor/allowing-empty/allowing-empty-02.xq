"",
for $x in (1 to 4)
  for $y allowing empty at $j in ($x to 3)
    return ($x, ",", $y, ",", $j,"
")
