let $x := for $i in 1 to 10 return { 'foo' || $i : 'bar' || $i }
return $x()

