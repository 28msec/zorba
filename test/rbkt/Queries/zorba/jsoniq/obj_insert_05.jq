declare variable $local:foo := {};

insert { "foo" : "bar", "blub" : "bar" } into $local:foo;

$local:foo
