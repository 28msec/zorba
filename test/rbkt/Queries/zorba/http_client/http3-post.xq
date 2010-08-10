import module namespace http = "http://expath.org/ns/http-client";

declare default element namespace "http://expath.org/ns/http-client";

let $req :=
  <request method="POST" href="http://www.zorba-xquery.com/rest-tests/request.php">
    <header name="foo" value="bar"/>
    <body media-type="text/plain">
      Dies ist ein kleiner Test
    </body>
  </request>
return http:send-request($req)[2]

