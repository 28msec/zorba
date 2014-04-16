declare namespace an = "http://zorba.io/annotations";

declare %an:strictlydeterministic function local:foo-sd($x)
{
  1
};

declare %an:cache function local:foo-c($x)
{
  1
};

declare function local:foo($x)
{
  1
};

local:foo(()),
local:foo-sd(()),
local:foo-c(())

