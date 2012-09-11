declare variable $foo := (1, 2, 3);
declare variable $boo := (1, 2, 3);

let $x := $foo
let $y := $boo
where count($x) eq 3
where count($y) gt 3
return 1
