import module namespace http = "http://www.zorba-xquery.com/modules/http-client";
import module namespace file = "http://www.zorba-xquery.com/modules/file";

declare variable $specPath as xs:string external;
declare variable $specURI  as xs:string external;

(
$specURI,
file:write($specPath, http:get($specURI)[2], <s method="xml" indent="yes" />/@*)
)

(:
(
$specURI,
file:write($specPath, http:get("http://www.w3.org/TR/xpath-functions/")[2], <s method="xml" indent="yes" />/@*)
)
:)