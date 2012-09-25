import module namespace j = "http://jsoniq.org/functions";

variable $a :=  [ 1, 2, 3];

append json ( 4, 5 ) into $a;

$a
