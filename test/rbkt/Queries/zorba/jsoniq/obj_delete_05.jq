import module namespace j = "http://jsoniq.org/functions";

variable $o := { "foo" : "bar" };

delete json $o.bar
