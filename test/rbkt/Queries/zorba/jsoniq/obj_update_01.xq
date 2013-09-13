import module namespace j = "http://jsoniq.org/functions";

variable $o := { "foo" : "bar" };

(
 replace value of json $o("foo") with "bar2", 
 rename json $o("foo") as "foo2",
 insert json { "bar" : "foo" } into $o
);

$o
