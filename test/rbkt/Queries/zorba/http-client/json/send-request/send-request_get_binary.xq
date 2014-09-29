jsoniq version "1.0";
import module namespace http = "http://zorba.io/modules/http-client";
declare namespace h = "http://expath.org/ns/http-client";

variable $req := 
{
  "method": "GET",
  "href": "http://zorbatest.28.io:8080/http-test-data/basic-auth/download.png",
  "authentication": {
    "auth-method": "Basic",               
    "username": "zorba",
    "password": "blub"
  }
};

let $res := http:send-request($req)
return
(
   $res.headers.("Content-Type") eq "image/png",
   $res.body.("media-type") eq "image/png",
   $res.headers.("Content-Length") eq "5577"
)
