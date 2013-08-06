import module namespace http="http://www.zorba-xquery.com/modules/http-client";

(: Connect to an invalid server :)
http:get-node("http://localhost:9998/cgi-bin/test-xml?foo&amp;")[2]

