count(
  for $x allowing empty at $i in ()
  where count($x) eq 1
  return ("[", $x, ",", $i, "]")
)
