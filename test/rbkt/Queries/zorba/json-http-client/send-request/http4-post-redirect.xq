jsoniq version "1.0";
import module namespace http="http://zorba.io/modules/http-client";

declare namespace h = "http://expath.org/ns/http-client";

http:send-request(
{
  "href": "http://zorbatest.lambda.nu:8080/remotequeue", 
  "method": "POST",
  "options": { 
    "follow-redirect": true
  }
});
