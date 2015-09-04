variable $query := "import module namespace m = \"http://zorba.io/module\"; 
           m:test()";
variable $module-1 := "module namespace m = \"http://zorba.io/module\"; 
                       import module namespace m2 = \"http://zorba.io/module2\";
                       declare function m:test() { m2:test() };";
variable $module-2 := "module namespace m2 = \"http://zorba.io/module2\"; 
                       declare function m2:test() { {\"Hello\" : 1/0} };";

variable $body := "query=" || encode-for-uri($query) || "&module=" || encode-for-uri($module-1) || "&module=" || encode-for-uri($module-2);

variable $response := test:post($test:zorba-endpoint || "/v1/evaluate", $body, "application/x-www-form-urlencoded", 500);
test:assert-equals("application/json;charset=UTF-8", $response.headers("Content-Type"));
test:assert-equals(
{
    "source": "Query (type error)",
    "code": "http://www.w3.org/2005/xqt-errors:XPTY0019",
    "message": "a non-last axis step produces non-node items",
    "stackTrace": [
        {
            "module": "http://zorba.io/module2",
            "lineNumber": 2,
            "columnNumber": 64,
            "lineNumberEnd": 2,
            "columnNumberEnd": 67
        },
        {
            "module": "http://zorba.io/module",
            "lineNumber": 3,
            "columnNumber": 52,
            "lineNumberEnd": 3,
            "columnNumberEnd": 61,
            "function": {
                "namespaceURI": "http://zorba.io/module2",
                "namespacePrefix": "m2",
                "localName": "test",
                "arity": 0
            }
        },
        {
            "module": "",
            "lineNumber": 2,
            "columnNumber": 12,
            "lineNumberEnd": 2,
            "columnNumberEnd": 20,
            "function": {
                "namespaceURI": "http://zorba.io/module",
                "namespacePrefix": "m",
                "localName": "test",
                "arity": 0
            }
        }
    ]
}
, parse-json($response.body.content));
