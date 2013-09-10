variable $o := { "foo" : "bar" };

(
 replace value of $o.foo with "bar2", 
 rename $o.foo as "foo2",
 insert { "bar" : "foo" } into $o,
 delete $o.foo
);

$o
