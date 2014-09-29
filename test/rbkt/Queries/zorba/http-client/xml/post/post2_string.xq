import module namespace http="http://www.zorba-xquery.com/modules/http-client";

variable $result :=
  http:post("http://zorbatest.28.io:8080/cgi-bin/test-text", "putstring");

$result[2]

