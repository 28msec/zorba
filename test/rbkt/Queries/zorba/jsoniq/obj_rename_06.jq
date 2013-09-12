variable $o := { "foo" : { "foo" : "bar" } };

rename json $o.foo[1].foo as "bar";

$o
