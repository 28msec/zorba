import module namespace http="http://www.zorba-xquery.com/modules/http-client";

variable $arg := <hello>there</hello>;
variable $result :=
  http:post("http://zorbatest.lambda.nu:8080/cgi-bin/test-text", $arg,
           "application/xml");

$result[2]

