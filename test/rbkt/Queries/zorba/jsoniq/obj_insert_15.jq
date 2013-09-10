declare variable $local:foo := { "bar" : "foo" };

insert ({ "foo" : "bar" }, { "foo" : "bar3" }) into $local:foo;

$local:foo
