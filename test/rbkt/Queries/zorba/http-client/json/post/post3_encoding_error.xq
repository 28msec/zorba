import module namespace http="http://zorba.io/modules/http-client";

variable $arg := "hello";
variable $result := http:post("http://localhost:99558/cgi-bin/test-text", $arg, "text plain; charset=mycharset");

$result[2]

