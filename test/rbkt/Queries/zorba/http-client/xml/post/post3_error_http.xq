import module namespace http="http://www.zorba-xquery.com/modules/http-client";

variable $arg := <hello>there</hello>;
variable $result :=
  http:post("http://localhost:99558/cgi-bin/test-text", $arg,
           "application/octet-stream");

$result[2]

