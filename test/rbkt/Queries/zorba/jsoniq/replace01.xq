import module namespace j = "http://www.jsoniq.org/functions";

variable $o := { "foo" : "bar" };
variable $a :=  [ 1, 2, 3];

(j:replace-value($o, "foo", $a), j:replace-value($a, 3, 4), j:replace-value($a, 1, $o));

$o, $a
