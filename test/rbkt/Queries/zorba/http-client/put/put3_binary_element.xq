import module namespace http="http://www.zorba-xquery.com/modules/http-client";

variable $arg := <hello>there</hello>;
variable $result :=
  http:put("http://zorbatest.lambda.nu:8080/cgi-bin/test-text", $arg,
           "application/octet-stream");

$result[2]

