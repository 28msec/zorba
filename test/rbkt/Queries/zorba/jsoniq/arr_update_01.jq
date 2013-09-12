import module namespace j = "http://jsoniq.org/functions";

variable $a :=  [ 1, 2, 3];

(
 replace value of json $a[[2]] with 4, 
 insert json (5, 6) into $a at position 2,
 delete json $a[[2]],
 delete json $a[[2]]
);

$a
