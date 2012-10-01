
variable $a := [ 1, 2, 3, 4 ];

(
insert json (4, 5) into $a at position 3,
delete json $a(3),
insert json (10, 15) into $a at position 4
);

$a
