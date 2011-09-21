count(
  for $x allowing empty at $i in (), $y in ()
  where count($x) eq 0
  return ("[", $x, ",", $i, ",", $y, "]")
)
