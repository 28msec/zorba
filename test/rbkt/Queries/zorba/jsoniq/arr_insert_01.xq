import module namespace j = "http://www.jsoniq.org/functions";

variable $a1 := [ 1, 2, 3 ];
variable $a2 := [  ];
variable $a3 := [  ];

insert json [ -5 to 0 ] into $a1 at position 1;
insert json [4 to 7] into $a1 at position j:size($a1) + 1;
insert json [1 to 3] into $a2 at position 1;
insert json [1 to 3] into $a3 at position j:size($a3) + 1;

$a1, $a2, $a3
