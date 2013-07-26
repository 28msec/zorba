import module namespace http="http://zorba.io/modules/http-client";

variable $arg := "hello";
variable $result :=
  http:put("http://localhost:99558/cgi-bin/test-text", $arg);

$result[2]

