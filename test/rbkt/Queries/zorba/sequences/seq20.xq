let $x := ("a", "b", "c")
let $y := fn:insert-before($x, 0, "z")
return $y
