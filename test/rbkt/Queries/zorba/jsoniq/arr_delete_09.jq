import module namespace j = "http://jsoniq.org/functions";

declare variable $o := [ [ 1, 2] ];

delete $o[[1]][[2]];

$o
