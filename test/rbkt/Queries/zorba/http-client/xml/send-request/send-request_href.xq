import module namespace http = "http://www.zorba-xquery.com/modules/http-client";

variable $res := 
http:send-request((), "http://zorbatest.lambda.nu:8080/cgi-bin/test-xml?querystring", ());

$res[2]

