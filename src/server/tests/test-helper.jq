jsoniq version "1.0";
module namespace test = "http://zorba.io/test-helper";

import module namespace http = "http://zorba.io/modules/http-client";
import module namespace string = "http://zorba.io/modules/string";

declare namespace an = "http://zorba.io/annotations";

declare variable $test:context as item* external := ();
declare variable $test:configuration as object external := ();
declare variable $test:zorba-endpoint as string external := ();

declare variable $test:last-request as object? := ();
declare variable $test:last-response as object? := ();

declare %an:sequential function test:get($href as string, $expected-statuses as integer+) as object
{
  test:send-request( 
    {
      "href" : $href,
      "method": "GET"
    }, $expected-statuses)
};

declare %an:sequential function test:post($href as string, $body as string, $content-type as string, $expected-statuses as integer+) as object
{
  test:send-request( 
    {
      "href" : $href,
      "method": "POST",
      "body":
      {
        "media-type": $content-type,
        "content": $body
      }
    }, $expected-statuses)
};

declare %an:sequential function test:send-request($request as object, $expected-statuses as integer+) as object
{
  trace("", "--> " || $request.method || " " || $request.href);
  
  $test:last-request := $request;
  $test:last-response :=
    copy $response := http:send-request($test:last-request)
    modify
      if ($response.body.content instance of string)
      then replace value of json $response.body.content with string:materialize($response.body.content)
      else ()
    return $response;
    
  trace("", "<-- " || string($test:last-response.status));  
  test:assert-any-of($expected-statuses, $test:last-response.status);
  
  $test:last-response
};

declare function test:assert-equals($expected as item*, $actual as item*) as ()
{
  if (not(fn:deep-equal($expected, $actual)))
  then test:error(QName("test:ASSERT"), "\nFailed Assertion\nExpected:\n" || serialize($expected) || "\nActual:\n" || serialize($actual));
  else ();
};

declare function test:assert-any-of($expected as item*, $actual as item) as ()
{
  if (not($actual = $expected))
  then test:error(QName("test:ASSERT"), "\nFailed Assertion\nExpected any of:\n" || serialize($expected) || "\nActual:\n" || serialize($actual));
  else ();
};

declare function test:error($code as QName, $description as string) as ()
{
  trace($test:last-request, "Last Request");
  trace($test:last-response, "Last Response");
  error($code, $description);
};

