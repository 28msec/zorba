import module namespace http = "http://zorba.io/modules/http-client";

let $uri := "http://zorbatest.28.io:8080/http-test-data/http1.xml"
for $method in http:options( $uri )
order by $method
return $method
