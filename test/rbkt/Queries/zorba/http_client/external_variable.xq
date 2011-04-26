import module namespace http = "http://www.zorba-xquery.com/modules/http-client";
declare variable $specURI as xs:string external;

http:get($specURI)[2]
