variable $response := test:post($test:zorba-endpoint || "/v1/evaluate", "1", "text/plain", 200);
test:assert-equals("text/plain;charset=UTF-8", $response.headers("Content-Type"));
test:assert-equals("1", $response.body.content);

$response := test:post($test:zorba-endpoint || "/v1/evaluate", "\"a\"", "text/plain", 200);
test:assert-equals("text/plain;charset=UTF-8", $response.headers("Content-Type"));
test:assert-equals("a", $response.body.content);

$response := test:post($test:zorba-endpoint || "/v1/evaluate", "xs:base64Binary(\"aGVsbG8=\")", "text/plain", 200);
test:assert-equals("text/plain;charset=UTF-8", $response.headers("Content-Type"));
test:assert-equals("aGVsbG8=", $response.body.content);

$response := test:post($test:zorba-endpoint || "/v1/evaluate", "import module namespace base64 = \"http://zorba.io/modules/base64\"; base64:decode(xs:base64Binary(\"aGVsbG8=\"))", "text/plain", 200);
test:assert-equals("text/plain;charset=UTF-8", $response.headers("Content-Type"));
test:assert-equals("hello", $response.body.content);

$response := test:post($test:zorba-endpoint || "/v1/evaluate", "<a/>", "text/plain", 200);
test:assert-equals("application/xml;charset=UTF-8", $response.headers("Content-Type"));
test:assert-equals("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<a/>", $response.body.content);

$response := test:post($test:zorba-endpoint || "/v1/evaluate", "{ \"a\": 1+1 }", "text/plain", 200);
test:assert-equals("application/json;charset=UTF-8", $response.headers("Content-Type"));
test:assert-equals({"a": 2}, parse-json($response.body.content));