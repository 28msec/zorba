import module namespace httpc = "http://expath.org/ns/http-client";

declare namespace http = "http://expath.org/ns/http-client";

let $req := <http:request method="GET"
  href="http://www.zorba-xquery.com/http-client/example_com.html"
  auth-method="Basic"
  send-authorization="true"
  username="zorba"
  password="blub"/>
return httpc:send-request($req)[1]/@status/fn:data(.)

