import module namespace http = "http://www.zorba-xquery.com/modules/http-client";
declare namespace h = "http://expath.org/ns/http-client";

variable $req := <h:request method="GET"
               href="http://zorbatest.28.io:8080/http-test-data/basic-auth/download.png"
               auth-method="Basic"
               send-authorization="true"
               username="zorba"
               password="blub"/>;

variable $http-res := http:send-request($req, (), ());

let $res := $http-res[1]
return (exists($res//h:header[@name = 'Content-Type' and @value = 'image/png']),
        exists($res//h:body[@media-type = 'image/png']),
        exists($res//h:header[@name = 'Content-Length' and @value = '5577']))
