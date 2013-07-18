jsoniq version "1.0";
import module namespace http="http://zorba.io/modules/http-client";

variable $result :=
  http:delete("http://zorbatest.lambda.nu:8080/cgi-bin/test-text");

$result.body.content
