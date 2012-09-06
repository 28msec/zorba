import module namespace j = "http://www.jsoniq.org/functions";

variable $o := { "foo" : "bar" };

(
  insert json { "bar" : "foo" } into $o, 
  insert json { "blub": "so" } into $o
);

$o
