import module namespace http="http://www.zorba-xquery.com/modules/http-client";

declare namespace exp="http://expath.org/ns/http-client";

data(
  http:head("http://localhost:99955/cgi-bin/test-xml")/@status
)


