import module namespace http="http://zorba.io/modules/http-client";

(: Connect to an invalid server :)
http:get("http://localhost:9998/cgi-bin/test-xml?foo&amp;")[2]

