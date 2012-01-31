import module namespace j = "http://www.jsoniq.org/functions";

variable $a := [ 1, 2 ];
(j:delete($a, 1), j:delete($a, 2));

$a
