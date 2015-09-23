variable $query := "import module namespace dctx = \"http://zorba.io/modules/dctx\"; dctx:snapshot-id()";
variable $body := "query=" || encode-for-uri($query);

variable $response := test:post($test:zorba-endpoint || "/v1/evaluate", $body, "application/x-www-form-urlencoded", 200);
test:assert-equals("text/plain;charset=UTF-8", $response.headers("Content-Type"));
test:assert-equals("0", $response.body.content);


$query := "import module namespace m = \"http://zorba.io/module\"; 
           m:test()";
variable $module-1 := "module namespace m = \"http://zorba.io/module\"; 
                       import module namespace m2 = \"http://zorba.io/module2\";
                       declare function m:test() { m2:test() };";
variable $module-2 := "module namespace m2 = \"http://zorba.io/module2\"; 
                       declare function m2:test() { {\"Hello\" : \"World\"} };";


$body := "query=" || encode-for-uri($query) || "&module=" || encode-for-uri($module-1) || "&module=" || encode-for-uri($module-2);

$response := test:post($test:zorba-endpoint || "/v1/evaluate", $body, "application/x-www-form-urlencoded", 200);
test:assert-equals("application/json;charset=UTF-8", $response.headers("Content-Type"));
test:assert-equals(
{
  "Hello": "World"
}, parse-json($response.body.content));
