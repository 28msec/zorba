import module namespace j = "http://www.jsoniq.org/functions";

variable $a1 := [ 1, 4, 5 ];
variable $a2 := [ 1, 2, 5 ];

insert json [ 2 to 3 ] into $a1 at position 2;
insert json [ 3 to 4 ] into $a2 at position 3;

$a1, $a2

