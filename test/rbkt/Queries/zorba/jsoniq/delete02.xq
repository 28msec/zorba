import module namespace j = "http://www.jsoniq.org/functions";

variable $a := [ "foo" , "bar" ];

j:delete($a, 1);

$a

