for $x in (1,2,3)
let $y := (4,5,6)
group by $x,$y collation "http://bla.com"
let $z := $y
where ($y < $z)
return $x
