import module namespace http = "http://www.expath.org/mod/http-client";

let $tmp := http:send-request((), "http://www.google.com/search?q=zorba+xquery")
return $tmp[1]/@status/fn:data(.)

