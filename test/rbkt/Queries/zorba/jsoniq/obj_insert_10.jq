declare variable $local:foo := { "bar" : "foo" };

declare variable $local:content := { "foo" : [ 1, 2, 3 ] };

insert $local:content into $local:foo;

append 4 into $local:content.foo;

$local:content
