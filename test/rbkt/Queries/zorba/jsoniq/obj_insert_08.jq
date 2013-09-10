declare variable $local:foo := { "bar" : "foo" };

declare variable $local:content := { "foo" : "bar" };

insert $local:content into $local:foo;

$local:content
