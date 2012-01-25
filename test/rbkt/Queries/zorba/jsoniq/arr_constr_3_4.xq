
import module namespace j = "http://www.jsoniq.org/functions";

count(
for $arr in j:values
  (
  [
    [1, "two", 3],
    [["four", 5], "six"],
    [7, ["eight", 9]]
  ]
  )
return j:flatten($arr)
)
