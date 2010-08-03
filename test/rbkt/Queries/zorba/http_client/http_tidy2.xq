import module namespace httpc = "http://expath.org/ns/http-client";

declare namespace http = "http://expath.org/ns/http-client";

let $req := <http:request method="GET" href="http://www.example.com"/>
return httpc:send-request($req)[1]/@status/fn:data(.)

