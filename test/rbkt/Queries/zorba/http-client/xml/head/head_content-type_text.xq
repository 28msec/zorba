import module namespace http="http://www.zorba-xquery.com/modules/http-client";

declare namespace exp="http://expath.org/ns/http-client";

data(
  http:head("http://zorbatest.28.io:8080/cgi-bin/test-text")
  /exp:header[@name="Content-Type"]/@value
)


