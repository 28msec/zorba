
count(
for $arr in jn:members
  (
  [
    [1, "two", 3],
    [["four", 5], "six"],
    [7, ["eight", 9]]
  ]
  )
return jn:flatten($arr)
)
