declare variable $local:foo := { "bar" : "foo" };

insert json [ 1 ] into $local:foo;

$local:foo
