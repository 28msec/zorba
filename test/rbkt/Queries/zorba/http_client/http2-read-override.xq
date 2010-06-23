import module namespace http = "http://expath.org/ns/http-client";
declare namespace h = "http://expath.org/ns/http-client";

let $req := <h:request method="GET"
               href="http://www.zorba-xquery.com/http-client/no-type.blub"
               auth-method="Basic"
               send-authorization="true"
               username="zorba"
               password="blub"
               override-media-type="text/html"/>
let $res := http:read($req, ())
return $res[2]

