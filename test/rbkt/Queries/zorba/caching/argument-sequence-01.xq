import module namespace debug = "http://zorba.io/modules/util-tests";
declare namespace an = "http://zorba.io/annotations";

declare %an:strictlydeterministic function local:test-02-cache($arg)
{
  serialize($arg),
  debug:uuid()
};

local:test-02-cache((xs:integer(1), <a/>, {"a" : 1}, [1]))[1],
local:test-02-cache((xs:integer(1), <a/>, {"a" : 1}, [1]))[1] 