import module namespace http = "http://expath.org/ns/http-client";
declare namespace h = "http://expath.org/ns/http-client";

let $req := <h:request method="GET"
               href="http://www.zorba-xquery.com/http-client/to-tidy.html"
               auth-method="Basic"
               send-authorization="true"
               username="zorba"
               password="blub"/>
let $res := http:read($req, ())
return $res[2]

