import module namespace http="http://www.zorba-xquery.com/modules/http-client";

http:get-text("http://zorbatest.28.io:8080/cgi-bin/test-text?querystring")[2]

