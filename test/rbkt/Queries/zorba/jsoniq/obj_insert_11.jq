declare variable $local:foo := { "bar" : "foo" };

insert json "foo" : "bar" into $local:foo;

$local:foo
