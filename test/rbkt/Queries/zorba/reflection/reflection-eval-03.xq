import module namespace reflection = "http://zorba.io/modules/reflection";

for $i in (1 to 2)
return reflection:eval-s("
  let $i := 3
  return $i
")
