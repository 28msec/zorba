import module namespace http="http://www.zorba-xquery.com/modules/http-client";

variable $arg := <h1>hi there</h1>;
variable $result :=
  http:put("http://zorbatest.lambda.nu:8080/cgi-bin/test-text", $arg,
           "text/html");

$result[2]

