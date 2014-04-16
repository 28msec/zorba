declare namespace an = "http://zorba.io/annotations";

declare %an:strictlydeterministic function local:foo($x as xs:integer)
{
};

declare function local:foo-det($x as xs:integer)
{
  local:foo($x)
};

declare %an:nondeterministic function local:foo-nondet($x as xs:integer)
{
  local:foo($x)
};

declare %an:sequential function local:foo-seq($x as xs:integer)
{
  local:foo($x)
};

declare %an:sequential %an:strictlydeterministic function local:foo-1($x as xs:integer)
{
};

declare %an:strictlydeterministic %an:exclude-from-cache-key(1) function local:foo-arg($x as xs:integer)
{
};

1