variable $o := { "foo" : "bar" };

(
insert { "bar" : "foo" } into $o, 
insert { "bar": "so" } into $o
);

$o
