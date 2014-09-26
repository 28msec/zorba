import module namespace http="http://www.zorba-xquery.com/modules/http-client";

http:get-node("http://zorbatest.28.io:8080/cgi-bin/test-xml?querystring")[2]
/body/query/text()

