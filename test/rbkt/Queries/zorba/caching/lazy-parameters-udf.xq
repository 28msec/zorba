declare namespace an = "http://zorba.io/annotations";

declare %an:cache function local:test-05-cache($x as xs:boolean, $y)
{
  if ($x)
  then $y
  else $x
};

declare %an:strictlydeterministic function local:test-05-sd($x as xs:boolean, $y)
{
  if ($x)
  then $y
  else $x
};

local:test-05-cache(false, error(xs:QName("local:ERR"), "ERR")),
local:test-05-sd(false, error(xs:QName("local:ERR"), "ERR")),
try {local:test-05-cache(true, error(xs:QName("local:ERR"), "ERR"))} catch * {"ERR"},
try {local:test-05-sd(true, error(xs:QName("local:ERR"), "ERR"))} catch * {"ERR"}
