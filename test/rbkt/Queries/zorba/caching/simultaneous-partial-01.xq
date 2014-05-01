declare namespace an = "http://zorba.io/annotations";

declare function local:dummy()
{
  ()
};


declare %an:cache function local:test-01-cache($x as xs:integer)
{
  if ($x < 10)
  then $x * $x
  else if ($x < 20)
  then local:dummy()
  else ($x, " == ", $x * $x)
};

(
for $i in local:test-01-cache(22)
where string($i) = 
 string(
  local:test-01-cache(try {xs:integer($i)} catch * {22})
  [1])
return $i
),
[local:test-01-cache(22)],
[local:test-01-cache(484)]