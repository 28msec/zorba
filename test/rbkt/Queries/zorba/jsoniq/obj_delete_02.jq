import module namespace j = "http://jsoniq.org/functions";

variable $o := { "foo" : "bar" };

(
delete $o.foo,
delete $o.foo
);

$o
