import module namespace http="http://zorba.io/modules/http-client";

variable $req :=
{
  "method": "POST",
  "href": "http://zorbatest.28.io:8080/http-test-data/request.php",  
  "body": {
    "media-type": "text/plain",
    "content": "
      Dies ist ein kleiner Test
    "
  },
  "options": {
    "user-agent": "28.io"
  }
};

parse-xml(http:send-request($req)("body")("content"))//*:header[@*:name="User-Agent"]/@value/string(.)