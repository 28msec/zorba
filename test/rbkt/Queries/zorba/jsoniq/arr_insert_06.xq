import module namespace j = "http://jsoniq.org/functions";

declare namespace jerr = "http://jsoniq.org/errors";

variable $a := [ 3 ];

insert json 2 into $a at position [ 1 ];

$a
