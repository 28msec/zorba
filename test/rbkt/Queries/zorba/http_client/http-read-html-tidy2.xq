import module namespace http = "http://expath.org/ns/http-client";
declare namespace h = "http://expath.org/ns/http-client";

let $h := <h:request method="GET"
               href="http://www.zorba-xquery.com/http-client/utf8.html"
               auth-method="Basic"
               send-authorization="true"
               username="zorba"
               password="blub"/>
let $r := http:send-request($h)
return <r>{($r//text()[starts-with(., "Fran")])[1]}</r>
