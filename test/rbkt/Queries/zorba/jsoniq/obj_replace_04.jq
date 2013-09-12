variable $o := { "foo" : { "foo" : "bar " } };
variable $a :=  [ 1, 2, 3];

replace value of json $o.foo[1].foo with $a;

$o
