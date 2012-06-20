import module namespace j = "http://www.jsoniq.org/functions";

variable $o := { "foo" : "bar" };
variable $a :=  [ 1, 2, 3];

replace json value of $o("foo") with $a; 


$o
