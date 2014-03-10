import module namespace http="http://zorba.io/modules/http-client";

variable $result :=
  http:delete("http://localhost:99558/cgi-bin/test-text");

$result[2]
