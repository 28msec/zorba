import module namespace http="http://www.zorba-xquery.com/modules/http-client";

declare namespace h = "http://expath.org/ns/http-client";

http:send-request(<h:request href="http://zorbatest.28.io:8080/remotequeue" method="POST" follow-redirect="true"/>, (), ());
