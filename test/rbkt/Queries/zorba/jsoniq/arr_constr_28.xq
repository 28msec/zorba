
import module namespace j = "http://www.jsoniq.org/functions";

count(j:flatten(
  [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
  ]
))
