import module namespace j = "http://www.jsoniq.org/functions";

variable $o := { "foo" : "bar" };

for $i in 1 to 10
return insert json  { concat("bar", $i) : concat("foo", $i) } into $o;

$o
