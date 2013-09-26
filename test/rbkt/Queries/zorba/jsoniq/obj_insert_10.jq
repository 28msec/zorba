declare variable $local:foo := { "bar" : "foo" };

declare variable $local:content := { "foo" : [ 1, 2, 3 ] };

insert json $local:content into $local:foo;

append json 4 into $local:content.foo;

$local:content
