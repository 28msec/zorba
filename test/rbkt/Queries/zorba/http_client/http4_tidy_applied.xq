import module namespace httpc = "http://expath.org/ns/http-client";
declare namespace http = "http://expath.org/ns/http-client";

httpc:send-request((), "http://www.example.com")[2],
httpc:send-request(<http:request href="http://www.example.com" method="GET" override-media-type="text/plain"/>)[2]
