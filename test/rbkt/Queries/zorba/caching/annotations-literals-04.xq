declare namespace an = "http://zorba.io/annotations";

declare %an:strictlydeterministic %an:exclude-from-cache-key(1) function local:foo()
{
  1
};

local:foo()