jsoniq version "1.0";
(: test content having a content type ending with +xml, i.e. image/svg+xml :)
import module namespace http = "http://zorba.io/modules/http-client";
declare namespace h = "http://expath.org/ns/http-client";

variable $req := 
{
  "method": "GET",
  "href": "http://zorbatest.28.io:8080/http-test-data/basic-auth/example.svg",
  "authentication": {
    "auth-method": "Basic",    
    "username": "zorba",
    "password": "blub"
  },
  "options": {
    "override-media-type": "application/xml; charset=utf-8"
  }
};

parse-xml(http:send-request($req).body.content)