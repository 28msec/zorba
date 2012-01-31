import module namespace j = "http://www.jsoniq.org/functions";

variable $o := pair { "foo" : "bar" };

j:delete($o, "foo")
