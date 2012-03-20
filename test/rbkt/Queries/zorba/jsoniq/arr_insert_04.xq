import module namespace j = "http://www.jsoniq.org/functions";

declare namespace jerr = "http://www.jsoniq.org/errors";

variable $a := [ 3 ];

(j:insert-before($a, 1, 2), j:insert-as-first($a,  1 to 2));

$a
