import module namespace http="http://www.zorba-xquery.com/modules/http-client";

variable $result :=
  http:delete("http://zorbatest.lambda.nu:8080/cgi-bin/test-text");

$result[2]
