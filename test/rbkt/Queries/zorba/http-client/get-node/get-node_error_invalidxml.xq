import module namespace http="http://www.zorba-xquery.com/modules/http-client";

(: The & in the query string causes the server to generate invalid XML :)
http:get-node("http://zorbatest.lambda.nu:8080/cgi-bin/test-xml?foo&amp;")[2]

