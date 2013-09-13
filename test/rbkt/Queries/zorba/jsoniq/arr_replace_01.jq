import module namespace j = "http://jsoniq.org/functions";

variable $o := { "foo" : "bar" };
variable $a :=  [ 1, 2, 3];

(
 replace value of json $o.foo with $a, 
 replace value of json $a[[3]] with 4, 
 replace value of json $a[[1]] with $o,
 replace value of json $a[[2]] with (1, 2)
);

$o, $a
