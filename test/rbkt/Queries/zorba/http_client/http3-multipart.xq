import module namespace httpc = "http://expath.org/ns/http-client";

declare namespace http = "http://expath.org/ns/http-client";

let $req :=
  <http:request method="POST" href="http://www.zorba-xquery.com/rest-tests/request.php">
    <http:header name="foo" value="bar"/>
    <http:multipart media-type="multipart/mixed">
      <http:header name="insidemutlipart" value="blubb"/>
      <http:body media-type="text/plain">
        A small text test
      </http:body>
      <http:body media-type="text/plain">
        Another small text body
      </http:body>
      <http:body media-type="img/png">lqenw</http:body>
    </http:multipart>
  </http:request>
return
  let $res := httpc:send-request($req)[2]
  return
    <result>
      <number-of-bodies>{fn:count($res//http:body)}</number-of-bodies>
      <headers>{$res//http:header[fn:not(fn:contains(@value/fn:data(.), "boundary"))]}</headers>
    </result>

