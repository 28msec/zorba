import module namespace j = "http://jsoniq.org/functions";

variable $o := { "foo" : "bar", "blub" : "bar" };

rename json $o("foo") as "blub"
