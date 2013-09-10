declare variable $local:foo := {};

declare variable $local:content := { "foo" : "bar" };

insert $local:content into $local:foo;

$local:foo
