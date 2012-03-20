import module namespace j = "http://www.jsoniq.org/functions";

variable $o := { "foo" : "bar" };

delete json $o("foo");

$o
