import module namespace j = "http://jsoniq.org/functions";

variable $o := { "foo" : "bar" };

(
 replace json value of $o("foo") with "bar2", 
 rename json $o("foo") as "foo2",
 insert json { "bar" : "foo" } into $o,
 delete json $o("foo")
);

$o
