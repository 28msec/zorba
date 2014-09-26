jsoniq version "1.0";
import module namespace http = "http://zorba.io/modules/http-client";
declare namespace err= "http://www.w3.org/2005/xqt-errors";

variable $res;
try
{{
variable $req:= {
  "method": "POST",
  "href": "http://zorbatest.28.io:8080/http-test-data/request.php",
  "headers": {"foo":"bar"},
  "body": {
    "media-type": "text/plain; something=charset; charSET = \"wrongone\" ; somethingelse=charset",
    "content": "
      Dies ist ein kleiner Test
    "
}};
http:send-request($req);
}}
catch http:CHARSET
{{
  $res := fn:substring-before($err:description,":");
}}

try
{{
variable $req:= {
  "method": "POST",
  "href": "http://zorbatest.28.io:8080/http-test-data/request.php",
  "headers": {"foo":"bar"},
  "body": {
    "media-type": "text/plain; charsetsomething=charset; charSET =wrongone; somethingelse=charset",
    "content": "
      Dies ist ein kleiner Test
    "
}};
http:send-request($req);
}}
catch http:CHARSET
{{
  $res := ($res, fn:substring-before($err:description,":"));
}}

$res