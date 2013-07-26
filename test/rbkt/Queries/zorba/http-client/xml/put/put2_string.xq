import module namespace http="http://www.zorba-xquery.com/modules/http-client";

variable $result :=
  http:put("http://zorbatest.lambda.nu:8080/cgi-bin/test-text", "putstring");

$result[2]

