variable $o := { "foo" : "bar" };

(
  insert { "bar" : "foo" } into $o, 
  insert { "blub": "so" } into $o
);

$o
