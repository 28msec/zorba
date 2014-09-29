import module namespace http="http://www.zorba-xquery.com/modules/http-client";

variable $arg := <h1>hi there</h1>;
variable $result :=
  http:post("http://zorbatest.28.io:8080/cgi-bin/test-text", $arg,
           "text/html");

$result[2]

