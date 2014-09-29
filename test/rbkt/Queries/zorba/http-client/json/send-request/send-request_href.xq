jsoniq version "1.0";
import module namespace http = "http://zorba.io/modules/http-client";

variable $req := 
{
  "method" : "GET",
  "href" : "http://zorbatest.28.io:8080/cgi-bin/test-xml?querystring"
};

parse-xml(http:send-request($req).body.content)