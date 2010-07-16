import schema namespace https = "http://expath.org/ns/http-client";

import module namespace http = "http://expath.org/ns/http-client";

let $tmp := http:send-request((), "http://www.google.com/search?q=zorba+xquery")
return $tmp[1]/@status/fn:data(.)

