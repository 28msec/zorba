declare variable $y := /works/employee;
declare context item := $y[9];
declare variable $x external := fn:position();
$x
