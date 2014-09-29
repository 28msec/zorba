jsoniq version "1.0";
import module namespace http="http://zorba.io/modules/http-client";

declare namespace h = "http://expath.org/ns/http-client";

variable $http-res-with := 
http:send-request(
{
  "href": "http://zorbatest.28.io:8080/remotequeue",
  "method": "HEAD",
  "options": {
    "follow-redirect": true
  }  
});

variable $http-res-without := 
http:send-request(
{
  "href": "http://zorbatest.28.io:8080/remotequeue",
  "method": "HEAD",
  "options": {
    "follow-redirect": false
  }  
});

let $status-with := $http-res-with.status
let $status-without := $http-res-without.status
return
  if ($status-without eq 301) then
    $status-with
  else "failed" 
  