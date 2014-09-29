import module namespace httpc = "http://www.zorba-xquery.com/modules/http-client";

declare namespace http = "http://expath.org/ns/http-client";

variable $req :=
  <http:request method="POST" href="http://zorbatest.28.io:8080/http-test-data/request.php">
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
  </http:request>;

variable $http-res := httpc:send-request($req, (), ());

variable $res := $http-res[2];

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

