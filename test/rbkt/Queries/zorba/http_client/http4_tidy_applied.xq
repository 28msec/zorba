import module namespace httpc = "http://expath.org/ns/http-client";
declare namespace http = "http://expath.org/ns/http-client";

httpc:send-request(
  <http:request href="http://www.zorba-xquery.com/http-client/example_com.html" method="GET" 
               auth-method="Basic"
               send-authorization="true"
               username="zorba"
               password="blub"/>)[2],
httpc:send-request(
  <http:request href="http://www.zorba-xquery.com/http-client/example_com.html" method="GET"
               override-media-type="text/plain"
               auth-method="Basic"
               send-authorization="true"
               username="zorba"
               password="blub"/>)[2]
