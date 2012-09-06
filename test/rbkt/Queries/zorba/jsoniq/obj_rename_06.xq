import module namespace j = "http://www.jsoniq.org/functions";

variable $o := { "foo" : { "foo" : "bar" } };

rename json $o("foo")[1]("foo") as "bar"; 

$o
