let $a := for $i in 1 to 10 return [ "foo" || $i, "bar" || $i]
return $a()
