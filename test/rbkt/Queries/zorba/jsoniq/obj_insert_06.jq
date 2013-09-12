declare variable $local:foo := {};

insert json { "foo" : ("bar1", "bar2"), "blub" : () } into $local:foo;

$local:foo
