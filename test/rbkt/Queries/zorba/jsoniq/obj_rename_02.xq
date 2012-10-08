import module namespace j = "http://jsoniq.org/functions";

variable $o := { "foo" : "bar" };

rename json $o("bar") as "blub"
