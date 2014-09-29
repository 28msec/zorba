import module namespace http="http://www.zorba-xquery.com/modules/http-client";

variable $arg := <!-- comment -->;
variable $result :=
  http:put("http://zorbatest.28.io:8080/cgi-bin/test-text", $arg);

$result[2]

