import module namespace j = "http://www.jsoniq.org/functions";

variable $o := { "foo" : "bar" };
variable $a :=  [ 1, 2, 3];

(
 replace json value of $o("foo") with $a, 
 replace json value of $a(3) with 4, 
 replace json value of $a(1) with $o
);

$o, $a
