declare variable $local:foo := {};

insert { "foo" : ("bar1", "bar2"), "blub" : () } into $local:foo;

$local:foo
