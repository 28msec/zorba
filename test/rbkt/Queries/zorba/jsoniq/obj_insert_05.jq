declare variable $local:foo := {};

insert json { "foo" : "bar", "blub" : "bar" } into $local:foo;

$local:foo
