import module namespace http = "http://expath.org/ns/http-client";
declare namespace h = "http://expath.org/ns/http-client";

let $req := <h:request method="GET"
               href="http://www.zorba-xquery.com/http-client/download.png"
               auth-method="Basic"
               send-authorization="true"
               username="zorba"
               password="blub"/>
let $res := http:send-request($req, ())[1]
return (exists($res//h:header[@name = 'Content-Type' and @value = 'image/png']),
        exists($res//h:body[@media-type = 'image/png']),
        exists($res//h:header[@name = 'Content-Length' and @value = '5577']))
