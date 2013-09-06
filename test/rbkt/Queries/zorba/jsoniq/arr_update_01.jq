import module namespace j = "http://jsoniq.org/functions";

variable $a :=  [ 1, 2, 3];

(
 replace value of $a[[2]] with 4, 
 insert (5, 6) into $a at position 2,
 delete $a[[2]],
 delete $a[[2]]
);

$a
