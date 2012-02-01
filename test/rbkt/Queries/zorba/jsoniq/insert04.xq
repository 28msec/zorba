import module namespace j = "http://www.jsoniq.org/functions";

variable $a1 := [ 1, 2, 3 ];
variable $a2 := [  ];
variable $a3 := [  ];

j:insert-as-first($a1, -5 to 0);
j:insert-as-last($a1, 4 to 7);
j:insert-as-first($a2,  1 to 3);
j:insert-as-last($a3,  1 to 3);

$a1, $a2, $a3
