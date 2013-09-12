import module namespace j = "http://jsoniq.org/functions";

declare variable $o := [ [ 1, 2] ];

delete json $o[[1]][[2]];

$o
