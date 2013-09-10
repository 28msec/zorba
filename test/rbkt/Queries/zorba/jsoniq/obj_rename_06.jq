variable $o := { "foo" : { "foo" : "bar" } };

rename $o.foo[1].foo as "bar";

$o
