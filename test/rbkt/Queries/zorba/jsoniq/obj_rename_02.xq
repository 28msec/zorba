import module namespace j = "http://www.jsoniq.org/functions";

variable $o := { "foo" : "bar" };

rename json $o("bar") as "blub"
