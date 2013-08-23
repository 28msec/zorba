jsoniq version "1.0";
import module namespace http="http://zorba.io/modules/http-client";

http:get-text("http://zorbatest.lambda.nu:8080/cgi-bin/test-xml").body.content

