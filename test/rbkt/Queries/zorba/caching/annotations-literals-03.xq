declare namespace an = "http://zorba.io/annotations";

declare %an:strictlydeterministic %an:exclude-from-cache-key(1, 2) function local:foo($x as xs:integer)
{
  1
};

local:foo(1)