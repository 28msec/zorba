jsoniq version "1.0";
import module namespace http = "http://zorba.io/modules/http-client";
declare namespace err= "http://www.w3.org/2005/xqt-errors";

variable $req2:= 
{
  "method": "POST",
  "href": "http://zorbatest.28.io:8080/http-test-data/request.php",
  "headers": {"foo":"bar"},
  "body": {
    "media-type": "multipart/form-data; boundary=----------------------------4ebf00fbcf09",
    "content": "
      Dies ist ein kleiner Test
    "
}};

parse-xml(http:send-request($req2)("body")("content"))