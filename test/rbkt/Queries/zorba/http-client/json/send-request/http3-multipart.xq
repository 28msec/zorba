xquery version "3.0";
import module namespace httpc = "http://zorba.io/modules/http-client";
import module namespace libjn = "http://jsoniq.org/function-library";

declare namespace http = "http://expath.org/ns/http-client";

variable $req :=
{
  "method": "POST", 
  "href": "http://zorbatest.28.io:8080/http-test-data/request.php",
  "headers": {"foo": "bar"},
  "multipart": {
    "media-type": "multipart/mixed",    
    "parts" : [
      {
        "headers": {"insidemutlipart": "blubb"},        
        "body": {
          "media-type": "text/plain",
          "content": "
        A small text test
      "
        }
      },
      {        
        "body": {
          "media-type": "text/plain",
          "content": " 
        Another small text body
      "
        }
      },
      {
        "body": {
          "media-type": "img/png",
          "content": "lqenw"
        }
      }      
    ]
  }
};

variable $res := parse-xml(httpc:send-request($req)("body")("content"));
<result>
      <number-of-bodies>{fn:count($res//http:body)}</number-of-bodies>
      <headers>{
        $res//http:header[fn:not(
          fn:contains(data(@value), "boundary")
            or
          fn:contains(data(@name), "------")
            or
          fn:contains(data(@name), "Content-Length"))]}</headers>
</result>