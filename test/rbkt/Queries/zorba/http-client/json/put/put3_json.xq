jsoniq version "1.0";
import module namespace http="http://zorba.io/modules/http-client";

variable $result := http:put("http://zorbatest.lambda.nu:8080/cgi-bin/test-text", serialize({"hello":"world"}), "application/json");
$result.body.content

