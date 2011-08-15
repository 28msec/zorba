import module namespace http="http://www.zorba-xquery.com/modules/http-client";

variable $arg := <!-- comment -->;
variable $result :=
  http:post("http://zorbatest.lambda.nu:8080/cgi-bin/test-text", $arg);

$result[2]

