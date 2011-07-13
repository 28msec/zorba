import module namespace http = "http://www.zorba-xquery.com/modules/http-client";

let $y  := http:get-node("http://www.zorba-xquery.com/rest-tests/http1.xml")//*
where  contains($y, "blub")
return $y

