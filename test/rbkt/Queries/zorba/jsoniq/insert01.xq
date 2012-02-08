import module namespace j = "http://www.jsoniq.org/functions";

variable $o := { "foo" : "bar" };

(j:insert-into($o, "bar" : "foo"), j:insert-into($o, "blub": "so")) ;

$o
