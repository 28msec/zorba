jsoniq version "1.0";
import module namespace http="http://zorba.io/modules/http-client";

for $i in (1 to 2)
return http:post("http://zorbatest.28.io:8080/cgi-bin/test-text", "poststring","text/plain");