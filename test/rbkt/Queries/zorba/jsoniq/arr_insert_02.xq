import module namespace j = "http://www.jsoniq.org/functions";

variable $a1 := [ 1, 4, 5 ];
variable $a2 := [ 1, 2, 5 ];

j:insert-before($a1, 2, 2 to 3);
j:insert-after($a2, 2, 3 to 4);

$a1, $a2

