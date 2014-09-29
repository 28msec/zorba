import module namespace http="http://zorba.io/modules/http-client";

parse-xml(http:get("http://zorbatest.28.io:8080/cgi-bin/test-xml?querystring")("body")("content"))/body/query/text()

