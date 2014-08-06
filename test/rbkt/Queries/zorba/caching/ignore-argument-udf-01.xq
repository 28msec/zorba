declare namespace an = "http://zorba.io/annotations";

declare %an:cache %an:exclude-from-cache-key(2) function local:test-06-cache($x as xs:integer, $y as xs:integer) as xs:integer
{
  $x + $y
};

declare %an:strictlydeterministic %an:exclude-from-cache-key(2) function local:test-06-sd($x as xs:integer, $y as xs:integer) as xs:integer
{
  $x + $y
};

{
  "cache":
  [
    local:test-06-cache(1,1),
    local:test-06-cache(1,2),
    local:test-06-cache(1,3),
    local:test-06-cache(2,1),
    local:test-06-cache(2,2),
    local:test-06-cache(2,3)
  ],
  "sd":
  [
    local:test-06-cache(1,1),
    local:test-06-cache(1,2),
    local:test-06-cache(1,3),
    local:test-06-cache(2,1),
    local:test-06-cache(2,2),
    local:test-06-cache(2,3)
  ]
}