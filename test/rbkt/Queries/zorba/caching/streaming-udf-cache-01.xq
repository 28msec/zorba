declare namespace an = "http://zorba.io/annotations";
import module namespace debug = "http://zorba.io/modules/util-tests";
import module namespace http = "http://zorba.io/modules/http-client";

declare %an:cache function local:test-04-cache($x, $y)
{
  debug:non-seeakable-streamable-string(),
  http:send-deterministic-request({ "href": "http://zorbatest.28.io:8080/cgi-bin/test-text"})("body"),
  serialize($x), 
  serialize($y)  
};

local:test-04-cache(debug:non-seeakable-streamable-string(), {debug:non-seeakable-streamable-string() : debug:non-seeakable-streamable-string()}),
local:test-04-cache(debug:non-seeakable-streamable-string(), {debug:non-seeakable-streamable-string() : debug:non-seeakable-streamable-string()}),
local:test-04-cache(http:send-deterministic-request({ "href": "http://zorbatest.28.io:8080/cgi-bin/test-text"})("body"), 1)
