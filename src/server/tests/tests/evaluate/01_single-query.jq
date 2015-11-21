variable $response := test:get($test:zorba-endpoint || "/v1/evaluate", 405);
test:assert-equals(
{
  "source" : "Server API", 
  "message" : "Invalid method in request <GET /v1/evaluate>. Supported methods for this endpoint are: POST." 
},
parse-json($response.body.content));

$response := test:post($test:zorba-endpoint || "/v1/evaluate", "1+", "text/plain", 500);
test:assert-equals(
{
    "source": "Query (static error)",
    "code": "http://www.w3.org/2005/xqt-errors:XPST0003",
    "message": "invalid expression: syntax error, unexpected \"end of file\"",
    "stackTrace": [
        {
            "module": "",
            "lineNumber": 1,
            "columnNumber": 3,
            "lineNumberEnd": 1,
            "columnNumberEnd": 4
        }
    ]
},
parse-json($response.body.content));

$response := test:post($test:zorba-endpoint || "/v1/evaluate", "1+1", "text/plain", 200);
test:assert-equals("text/plain;charset=UTF-8", $response.headers("Content-Type"));
test:assert-equals("2", $response.body.content);


variable $query := "import module namespace dctx = \"http://zorba.io/modules/dctx\"; dctx:snapshot-id()"; 
$response := test:post($test:zorba-endpoint || "/v1/evaluate", $query, "text/plain", 200);
test:assert-equals("text/plain;charset=UTF-8", $response.headers("Content-Type"));
test:assert-equals("0", $response.body.content);

