variable $o := { "foo" : "bar" };

for $i in 1 to 10
return insert { concat("bar", $i) : concat("foo", $i) } into $o;

$o
