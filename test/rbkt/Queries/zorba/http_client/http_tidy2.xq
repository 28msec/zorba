import module namespace httpc = "http://www.expath.org/mod/http-client";
import schema namespace http = "http://www.expath.org/mod/http-client";

let $req := validate { <http:request method="GET" href="http://www.example.com"/> }
return httpc:send-request($req)[1]/@status/fn:data(.)

