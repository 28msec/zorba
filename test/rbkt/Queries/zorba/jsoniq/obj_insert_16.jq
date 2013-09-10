variable $o := { "foo" : "bar" };

(
insert { "bar" : "foo" } into $o, 
insert { "baz" : "foo", "bar": "so" } into $o
);

$o
