jsoniq version "1.0";
import module namespace http="http://zorba.io/modules/http-client";

http:get-text("http://zorbatest.28.io:8080/cgi-bin/test-binary").body.content