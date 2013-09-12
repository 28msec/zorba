variable $o := { "foo" : "bar" };
variable $a :=  [ 1, 2, 3];

replace value of json $o.foo with $a; 

$o
