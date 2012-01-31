import module namespace j = "http://www.jsoniq.org/functions";

variable $a := [ 1, 2 ];

j:delete($a, 3)
