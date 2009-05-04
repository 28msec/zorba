let $x := (98.5, 98.3, 98.9)
return fn:count($x[. > 100])
