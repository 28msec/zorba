import module namespace j = "http://jsoniq.org/functions";

variable $o := { "foo" : "bar" };
variable $a :=  [ 1, 2, 3];

replace value of json $o("foo") with ($a, 10, 100, 1000); 


$o
