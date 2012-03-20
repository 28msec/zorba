import module namespace j = "http://www.jsoniq.org/functions";

variable $a := [ "foo" , "bar" ];

delete json $a(1);

$a

