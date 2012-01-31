import module namespace j = "http://www.jsoniq.org/functions";

variable $o := { "foo" : "bar" };

j:delete($o, "bar")
