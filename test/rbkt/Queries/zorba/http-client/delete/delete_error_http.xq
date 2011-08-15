import module namespace http="http://www.zorba-xquery.com/modules/http-client";

variable $result :=
  http:delete("http://localhost:99558/cgi-bin/test-text");

$result[2]
