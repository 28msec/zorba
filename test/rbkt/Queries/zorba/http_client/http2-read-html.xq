import module namespace http = "http://expath.org/ns/http-client";
declare namespace h = "http://expath.org/ns/http-client";

let $req := <h:request method="GET"
               href="http://www.zorba-xquery.com/http-client/doc.html"
               auth-method="Basic"
               send-authorization="true"
               username="zorba"
               password="blub"/>
let $res := http:send-request($req, ())
return $res[2]

