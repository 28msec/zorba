import module namespace j = "http://www.jsoniq.org/functions";

variable $a := [ 1, 2 ];

delete json $a(-1)
