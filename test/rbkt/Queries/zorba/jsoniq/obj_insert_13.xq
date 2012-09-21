declare variable $local:foo := { "bar" : "foo" };

insert json () into $local:foo;

$local:foo
