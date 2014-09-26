import module namespace http="http://www.zorba-xquery.com/modules/http-client";

declare namespace h = "http://expath.org/ns/http-client";

variable $http-res-with := 
http:send-request(<h:request href="http://zorbatest.28.io:8080/remotequeue" method="HEAD" follow-redirect="true"/>, (), ());

variable $http-res-without := 
http:send-request(<h:request href="http://zorbatest.28.io:8080/remotequeue" method="HEAD" follow-redirect="false"/>, (), ());

let $status-with := $http-res-with[1]/@status/data(.)
let $status-without := $http-res-without[1]/@status/data(.)
return
  if ($status-without eq 301) then
    $status-with
  else "failed"
