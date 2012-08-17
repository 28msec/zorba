import module namespace j = "http://www.jsoniq.org/functions";

variable $o := { "foo" : { "foo" : "bar " } };
variable $a :=  [ 1, 2, 3];

replace json value of $o("foo")[1]("foo") with $a; 


$o
