import module namespace httpc = "http://expath.org/ns/http-client";
import schema namespace http = "http://expath.org/ns/http-client";

let $req := validate { <http:request method="GET" href="http://www.example.com"/> }
return httpc:send-request($req)[1]/@status/fn:data(.)

