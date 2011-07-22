import module namespace reflection = "http://www.zorba-xquery.com/modules/reflection";

for $i in (1 to 2)
return reflection:eval-sequential("
  let $i := 3
  return $i
")
