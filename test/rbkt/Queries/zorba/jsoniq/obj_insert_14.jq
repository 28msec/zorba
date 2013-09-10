declare variable $local:foo := { "bar" : "foo" };

insert ({ "foo" : "bar" }, { "foo2" : "bar3" }) into $local:foo;

$local:foo
