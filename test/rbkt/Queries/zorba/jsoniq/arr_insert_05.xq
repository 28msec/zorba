import module namespace j = "http://www.jsoniq.org/functions";

declare namespace jerr = "http://www.jsoniq.org/errors";

variable $a := [ 3 ];

insert json 2 into $a at position <a>1</a>;

$a
